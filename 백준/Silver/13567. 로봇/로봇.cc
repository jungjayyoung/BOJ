#include <iostream>
#include <string>

using namespace std;

int board[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int M,n;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> M >> n;

    int cur_x = 0;
    int cur_y = 0;
    int dir = 0;

    while (n--) {

        string order;
        int num;


        cin >> order >> num;


        if (order == "MOVE") {
            int nextx = cur_x + (num * dx[dir]);
            int nexty = cur_y + (num * dy[dir]);
            if (nextx < 0 || nextx >= M || nexty < 0 || nexty >= M) {
                cout << -1;
                return 0;
            }

            cur_x = nextx;
            cur_y = nexty;

        } else if (order == "TURN") {
            //90도 회전
            if (num == 0) {
                dir++;
                if (dir > 3) {
                    dir = 0;
                }

            } else if (num == 1) {

                dir--;
                if (dir < 0) {
                    dir = 3;
                }
            }
        }


    }


    cout << cur_x << " " << cur_y;


    return 0;
}