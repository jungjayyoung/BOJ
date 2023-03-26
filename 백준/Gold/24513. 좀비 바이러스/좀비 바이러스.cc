#include <iostream>
#include <queue>

using namespace std;


int n, m;
int map[1001][1001];
int visited[1001][1001][2];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

queue<pair<pair<int,int>,int>> virus1;
queue<pair<pair<int,int>,int>> virus2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;


    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
            if (map[y][x] == 1) {
                virus1.push({{x, y}, 1});
                visited[y][x][0] = 1;
                visited[y][x][1] = 1;
            } else if (map[y][x] == 2) {
                virus2.push({{x, y}, 1});
                visited[y][x][0] = 2;
                visited[y][x][1] = 1;
            }
        }
    }


    while (!virus1.empty() || !virus2.empty()) {

        int cur1_size = virus1.size();
        bool check1 = false;

        for (int i = 0; i < cur1_size; i++) {
            int curx = virus1.front().first.first;
            int cury = virus1.front().first.second;
            int cur_cnt = virus1.front().second;

            virus1.pop();

            if(visited[cury][curx][0] == 3) continue;

            for (int j = 0; j < 4; j++) {
                int nx = curx + dx[j];
                int ny = cury + dy[j];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(map[ny][nx] == -1) continue;

                if (visited[ny][nx][0] == 0 && visited[ny][nx][1] == 0) {
                    visited[ny][nx][0] = 1;
                    visited[ny][nx][1] = cur_cnt + 1;
                    check1 = true;
                    virus1.push({{nx, ny}, cur_cnt + 1});
                }else if (visited[ny][nx][0] == 2 && map[ny][nx] == 0 && visited[ny][nx][1] == cur_cnt + 1) {
                    visited[ny][nx][0] = 3;
                }
            }
        }

        int cur2_size = virus2.size();
        bool check2 = false;
        for (int i = 0; i < cur2_size; i++) {

            int curx = virus2.front().first.first;
            int cury = virus2.front().first.second;
            int cur_cnt = virus2.front().second;

            virus2.pop();
            if(visited[cury][curx][0] == 3) continue;

            for (int j = 0; j < 4; j++) {
                int nx = curx + dx[j];
                int ny = cury + dy[j];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(map[ny][nx] == -1) continue;

                if (visited[ny][nx][0] == 0 && visited[ny][nx][1] == 0) {
                    visited[ny][nx][0] = 2;
                    visited[ny][nx][1] = cur_cnt + 1;
                    check2 = true;
                    virus2.push({{nx, ny}, cur_cnt + 1});
                } else if (visited[ny][nx][0] == 1 && map[ny][nx] == 0 && visited[ny][nx][1] == cur_cnt + 1) {
                    visited[ny][nx][0] = 3;
                }
            }



        }
//        for (int y = 0; y < n; y++) {
//            for (int x = 0; x < m; x++) {
//                cout << visited[y][x][0] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";

        if(!check1 && !check2) break;

    }


    //cout << "\n";

    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (visited[y][x][0] == 1) {
                cnt1++;
            } else if (visited[y][x][0] == 2) {
                cnt2++;
            } else if (visited[y][x][0] == 3) {
                cnt3++;
            }
        }
    }


    cout << cnt1 << " " << cnt2 << " " << cnt3;
    return 0;
}