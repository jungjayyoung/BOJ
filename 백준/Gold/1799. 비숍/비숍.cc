#include <iostream>
#include <vector>

using namespace std;

int n;
int map[11][11];
int visited1[21];
int visited2[21];
int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};
int ans[2];
int S;

vector<pair<int,int>> v[21];


void bt(int idx,int cnt,int color){

    bool check = false;


    if (idx >= S) {
        ans[color] = max(ans[color], cnt);
        return;
    }

    for (int i = 0; i < v[idx].size(); i++) {

        int xx = v[idx][i].first;
        int yy = v[idx][i].second;

        if((xx + yy) % 2 == color) continue;
        if (!visited1[yy + xx] && !visited2[xx - yy + (n - 1)]) {
            visited1[yy + xx] = 1;
            visited2[xx - yy + (n - 1)] = 1;
            check = true;
            bt(idx + 1, cnt + 1,color);
            visited1[yy + xx] = 0;
            visited2[xx - yy + (n - 1)] = 0;

        }
    }

    if (!check) {
        bt(idx + 1, cnt,color);
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;

    for (int y = 0; y < n; y++) {

        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    // 정방향 대각선 인덱스가 i에 해당한다.
    for (int i = 0; i < 2*(n-1)+1; i++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (x + y == i && map[y][x] == 1) {
                    v[i].push_back({x, y});
                }
            }
        }
    }

    for (int i = 0; i < 2*(n-1)+1; i++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (x + y == i && map[y][x] == 1) {
                    v[i].push_back({x, y});
                }
            }
        }
    }

    S = 2*(n-1)+1;

    bt(0, 0,0);

    bt(0, 0, 1);

    cout << ans[0] + ans[1];


    return 0;
}