#include <iostream>
#include <string>


using namespace std;

int r, c, n;

char map[201][201];
int visited[201][201];
int bomb_check[201][201];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> n;

    for (int y = 0; y < r; y++) {

        string str;
        cin >> str;
        for (int x = 0; x < c; x++) {
            map[y][x] = str[x];
            if (map[y][x] == 'O') {
                visited[y][x] = 1;
            }
        }
    }

    int cnt = 1;

    while (cnt < n) {
        cnt++;

        if (cnt % 2 == 0) {
            for (int y = 0; y < r; y++) {
                for (int x = 0; x < c; x++) {
                    if (map[y][x] == '.') {
                        map[y][x] = 'O';
                        visited[y][x] = 1;
                    } else {
                        // 폭탄이 설치된 곳은 타이머를 1초 늘려서 2가 된다.
                        visited[y][x]++;
                    }
                }
            }
        } else {

            //폭발할 위치들 체크하기
            for (int y = 0; y < r; y++) {
                for (int x = 0; x < c; x++) {
                    if (visited[y][x] == 2) {
                        bomb_check[y][x] = 1;
                        visited[y][x] = 0;
                        for (int i = 0; i < 4; i++) {
                            int nx = x + dx[i];
                            int ny = y + dy[i];

                            if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;

                            // 폭발하는 곳은 visited를 0으로 바꿔준다.

                            bomb_check[ny][nx] = 1;
                        }
                    }
                }
            }

            //폭발시키기 + 다른 폭탄 1초 늘리기
            for (int y = 0; y < r; y++) {
                for (int x = 0; x < c; x++) {
                    if (bomb_check[y][x]) {
                        map[y][x] = '.';
                        bomb_check[y][x] = 0;
                        visited[y][x] = 0;
                    }
                }
            }

        }


    }


    for (int y = 0; y < r; y++) {

        for (int x = 0; x < c; x++) {
            cout <<map[y][x];
        }
        cout << "\n";
    }
    cout << "\n";



    return 0;
}