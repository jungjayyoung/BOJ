#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int h, w;
char map[102][102];
int visited[102][102];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool is_key[26];



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;




    for (int i = 0; i < t; i++) {

        // 초기화
        fill(&visited[0][0], &visited[103][0], 0);
        fill(is_key, is_key + 27, false);

        cin >> h >> w;
        // 가장자리 전부 .으로 만들기
        for (int x = 0; x < 102; x++) {
            map[0][x] = '.';
            map[h + 1][x] = '.';
        }

        // 가장자리 전부 .으로 만들기
        for (int y = 0; y < 102; y++) {
            map[y][0] = '.';
            map[y][w + 1] = '.';
        }

        for (int y = 1; y <= h; y++) {
            string str;
            cin >> str;
            for (int x = 1; x <= w; x++) {
                map[y][x] = str[x - 1];
            }
        }

        // 가지고 있는 열쇠 입력받기
        string a;
        cin >> a;

        // 처음에 가지고 있는 key를 true로 해준다.
        if (a != "0") {
            for (int i = 0; i < a.size(); i++) {
                is_key[a[i] - 'a'] = true;
            }
        }

        queue<pair<int,int>> q;
        queue<pair<int, int>> not_yet_door[26];


        q.push({0, 0});
        visited[0][0] = 1;
        int ans = 0;

        while (!q.empty()) {

            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = curx + dx[i];
                int ny = cury + dy[i];

                if (nx < 0 || ny < 0 || nx > w + 1 || ny > h + 1) {
                    continue;
                }

                if(map[ny][nx] == '*') continue;

                if (map[ny][nx] == '.' && !visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    q.push({nx, ny});
                } else if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z' && !visited[ny][nx]) {

                    // 1. 문을 열 수 있는 열쇠가 있는 경우
                    if (is_key[map[ny][nx] - 'A']) {
                        visited[ny][nx] = 1;
                        q.push({nx, ny});
                    // 2. 문을 열 수 있는 열쇠가 없는 경우
                    }else{
                        not_yet_door[map[ny][nx] - 'A'].push({nx, ny});
                    }

                //  열쇠를 찾은 경우
                } else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z' && !visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    q.push({nx, ny});

                    // 열쇠를 true로 만들어주고
                    is_key[map[ny][nx] - 'a'] = true;
                    // 못 열었던 문들의 좌표를 전부 큐에 집어 넣는다.
                    while (!not_yet_door[map[ny][nx] - 'a'].empty()) {
                        int xx = not_yet_door[map[ny][nx] - 'a'].front().first;
                        int yy = not_yet_door[map[ny][nx] - 'a'].front().second;
                        not_yet_door[map[ny][nx] - 'a'].pop();
                        visited[yy][xx] = 1;
                        q.push({xx, yy});
                    }

                // 문서를 찾은 경우
                } else if (map[ny][nx] == '$' && !visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    q.push({nx, ny});
                    ans++;
                }
            }

        }

        cout << ans << "\n";

    }

    return 0;
}
