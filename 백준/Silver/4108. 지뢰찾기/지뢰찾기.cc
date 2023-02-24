#include <iostream>
#include <string>

using namespace std;


int r, c;

char map[101][101];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (1) {
        cin >> r >> c;

        if (r == 0 && c == 0) {
            break;
        }

        for (int y = 0; y < r; y++) {
            string str;
            cin >> str;
            for (int x = 0; x < c; x++) {
                map[y][x] = str[x];
            }
        }


        for (int y = 0; y < r; y++) {

            for (int x = 0; x < c; x++) {
                if (map[y][x] == '*') {
                    cout << '*';
                }else{
                    int cnt = 0;
                    for (int i = 0; i < 8; i++) {
                        int nx = dx[i] + x;
                        int ny = dy[i] + y;

                        if (nx < 0 || ny < 0 || nx >= c || ny >= r) {
                            continue;
                        }

                        if(map[ny][nx] == '*') cnt++;
                    }
                    cout << cnt;
                }
            }
            cout << "\n";
        }





    }


    return 0;
}

