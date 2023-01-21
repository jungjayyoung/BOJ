#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>


using namespace std;

int n, m;
int map[51][51];
int visited[51][51];
int visited2[11];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<pair<int,int>> v;
vector<pair<int,int>> pos;
int ans = 98765432;

void bfs(){
    queue<pair<int,int>> virus;
    for (int i = 0; i < v.size(); i++) {
        virus.push({v[i].first, v[i].second});
        visited[v[i].second][v[i].first] = 1;
    }
    int cnt = 0;

    while (!virus.empty()) {

        int S = virus.size();

        for (int j = 0; j < S; j++) {

            int curx = virus.front().first;
            int cury = virus.front().second;
            virus.pop();

            for (int i = 0; i < 4; i++) {
                int nx = curx + dx[i];
                int ny = cury + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (map[ny][nx] == 1) continue;

                if (!visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    virus.push({nx, ny});
                }
            }

        }
        if(virus.size() != 0) cnt++;
    }

    bool check = false;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if(map[y][x] == 1) continue;
            if(visited[y][x] == 0) {
                check = true;
                return;
            }
        }
    }

    if (!check) {
        ans = min(ans, cnt);
    }

}

void bt(int idx){

    if (v.size() >= m) {

        fill(&visited[0][0], &visited[51][0], 0);

        bfs();

        return;
    }


    for (int i = idx; i < pos.size(); i++) {

        if (!visited2[i]) {
            visited2[i] = 1;
            v.push_back({pos[i].first, pos[i].second});
            bt(idx + 1);
            v.pop_back();
            visited2[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;


    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
            if (map[y][x] == 2) {
                pos.push_back({x, y});

            }
        }
    }

    bt(0);

    if (ans == 98765432) {
        cout << -1;
    }else
        cout << ans;


    return 0;
}