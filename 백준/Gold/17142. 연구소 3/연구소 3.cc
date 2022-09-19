#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int board[51][51];

vector<pair<int,int>> virus_list;
vector<pair<int, int>> selected_virus_list;

int visited[51][51];
int visited2[11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;


queue<pair<pair<int,int>,int>> q;
int ans = 8765;

void bfs(){

    int max_cnt = 0;

    while (!q.empty()) {

        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        int cur_cnt = q.front().second;

        q.pop();
        if (board[cur_y][cur_x] != 2) {
            max_cnt = max(max_cnt, cur_cnt);
        }


        for (int i = 0; i < 4; i++) {

            int nextx = cur_x + dx[i];
            int nexty = cur_y + dy[i];

            if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n) {
                continue;
            }

            if (!visited[nexty][nextx] && board[nexty][nextx] != 1) {
                visited[nexty][nextx] = 1;
                q.push({{nextx, nexty}, cur_cnt + 1});
            }

        }

    }


    // 빈칸을 채우지 못한 빈공간이 존재하면 ans 갱신하지 않고 바로 return

    for (int y = 0; y < n; y++) {

        for (int x = 0; x < n; x++) {
            if (visited[y][x] == 0 && board[y][x] != 1) {

                return;
            }
        }
    }

    ans = min(ans, max_cnt);


}

void bt(int cnt,int cur){


    if (cnt >= m) {
        fill(&visited[0][0], &visited[51][0], 0);

        for (int i = 0; i < selected_virus_list.size(); i++) {
            q.push({{selected_virus_list[i].first, selected_virus_list[i].second}, 0});
            visited[selected_virus_list[i].second][selected_virus_list[i].first] = 1;
        }

        bfs();

        return;
    }

    for (int i = 0; i < virus_list.size(); i++) {


        if (!visited2[i] && i > cur) {
            visited2[i] = 1;
            selected_virus_list.push_back({virus_list[i].first, virus_list[i].second});
            bt(cnt + 1,i);
            selected_virus_list.pop_back();
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

            cin >> board[y][x];
            if (board[y][x] == 2) {
                virus_list.push_back({x, y});
            }

        }
    }


    bt(0,-1);


    if (ans == 8765) {
        cout << -1;
    }else
        cout << ans;

    return 0;
}