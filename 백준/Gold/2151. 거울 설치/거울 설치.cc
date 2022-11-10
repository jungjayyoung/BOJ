#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


char map[51][51];
int visited[51][51][4];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n;
int sx, sy, ex, ey;
int ans = 3000;
bool check = false;
vector<pair<int,int>> v;

// 설치하지 않는 경우를 우선적으로 생각한다.

//0: 서 1: 남 2: 동 3: 북

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int y = 0; y < n; y++) {

        string str;
        cin >> str;
        for (int x = 0; x < n; x++) {
            map[y][x] = str[x];
            if (map[y][x] == '#') {
                v.push_back({x, y});
            }
        }
    }
    sx = v[0].first;
    sy = v[0].second;
    ex = v[1].first;
    ey = v[1].second;


    for (int i = 0; i < 4; i++) {

        queue<pair<pair<int,int>,pair<int,int>>> q;

        fill(&visited[0][0][0], &visited[51][0][0], 3000);
        q.push({{sx,sy},{i,0}});
        visited[sy][sx][0] = 3000;
        visited[sy][sx][1] = 3000;
        visited[sy][sx][2] = 3000;
        visited[sy][sx][3] = 3000;
        while (!q.empty()) {

            int x = q.front().first.first;
            int y = q.front().first.second;
            int dir = q.front().second.first;
            int cnt = q.front().second.second;

            q.pop();

            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 범위를 벗어나면 리턴
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            // 벽을 만나면 리턴
            if(map[ny][nx] == '*') continue;

            // 다른 문을 만나면 리턴
            if (map[ny][nx] == '#' && nx == ex && ny == ey) {

                if (visited[ny][nx][dir] > cnt) {
                    ans = min(ans, cnt);
                }
            }

            if (map[ny][nx] == '.') {
                if (visited[ny][nx][dir] > cnt) {
                    visited[ny][nx][dir] = cnt;
                    q.push({{nx, ny}, {dir, cnt}});
                }

            } else if (map[ny][nx] == '!') {

                // 그냥 지나칠 경우
                if (visited[ny][nx][dir] > cnt) {
                    visited[ny][nx][dir] = cnt;
                    q.push({{nx,ny},{dir,cnt}});
                }

                //0: 서 1: 남 2: 동 3: 북
                if (dir == 0) {
                    if(visited[ny][nx][1] > cnt + 1) {
                        visited[ny][nx][1] = cnt + 1;
                        q.push({{nx,ny},{1,cnt+1}});
                    }
                    if(visited[ny][nx][3] > cnt + 1) {
                        visited[ny][nx][3] = cnt + 1;
                        q.push({{nx,ny},{3,cnt+1}});
                    }


                } else if (dir == 1) {
                    if(visited[ny][nx][0] > cnt + 1) {
                        visited[ny][nx][0] = cnt + 1;
                        q.push({{nx,ny},{0,cnt+1}});
                    }

                    if(visited[ny][nx][2] > cnt + 1) {
                        visited[ny][nx][2] = cnt + 1;
                        q.push({{nx,ny},{2,cnt+1}});
                    }

                } else if (dir == 2) {
                    if(visited[ny][nx][1] > cnt + 1) {
                        visited[ny][nx][1] = cnt + 1;
                        q.push({{nx,ny},{1,cnt+1}});
                    }
                    if(visited[ny][nx][3] > cnt + 1) {
                        visited[ny][nx][3] = cnt + 1;
                        q.push({{nx,ny},{3,cnt+1}});
                    }

                } else if (dir == 3) {

                    if(visited[ny][nx][0] > cnt + 1) {
                        visited[ny][nx][0] = cnt + 1;
                        q.push({{nx,ny},{0,cnt+1}});
                    }
                    if(visited[ny][nx][2] > cnt + 1) {
                        visited[ny][nx][2] = cnt + 1;
                        q.push({{nx,ny},{2,cnt+1}});
                    }

                }



            }

        }

    }


    cout << ans;


    return 0;
}