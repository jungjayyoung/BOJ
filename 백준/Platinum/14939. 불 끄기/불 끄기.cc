#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define NMAX 1000
using namespace std;


char board[12][12];
vector<pair<int,int>> pos;
int ans = NMAX;

void bt(int idx,int btn_click){



    // 0~99 의 idx를 다 탐색하면 bt 종료
    if (idx >= 100) {

        // 전구가 다 꺼져있는지 확인하자!
        for (int y = 1; y <= 10; y++) {

            for (int x = 1; x <= 10; x++) {
                // 전구가 켜져있으면 정답조건 불만족하므로 return
                if (board[y][x] == 'O') {
                    return;
                }
            }
        }
        // 전구가 다 꺼져 있으면 ans 갱신
        ans = min(ans, btn_click);


        return;
    }

    int x = pos[idx].first;
    int y = pos[idx].second;


    // 두번째 줄부터 bt 과정
    if (idx >= 10) {
        // 두번째 줄부터는 위의 전구가 꺼져 있으면 키면 안되므로 누르지 않고 다음 bt로 간다.
        if (board[y - 1][x] == '#') {
            bt(idx + 1, btn_click);
        } else if (board[y - 1][x] == 'O') {
            // 위의 전구가 켜져있을 때는 전구를 눌러준다.

            // 누르는 전구 자기 자신
            if (board[y][x] == '#') {
                board[y][x] = 'O';
            } else if (board[y][x] == 'O') {
                board[y][x] = '#';
            }

            // 버튼 누른 전구 위쪽
            board[y - 1][x] = '#';

            // 버튼 누른 전구 왼쪽
            if (x - 1 != 0) {
                if (board[y][x - 1] == '#') {
                    board[y][x - 1] = 'O';
                } else if (board[y][x - 1] == 'O') {
                    board[y][x - 1] = '#';
                }
            }

            //버튼 누른 전구 오른쪽
            if (x + 1 != 11) {
                if (board[y][x + 1] == '#') {
                    board[y][x + 1] = 'O';
                } else if (board[y][x + 1] == 'O') {
                    board[y][x + 1] = '#';
                }
            }
            // 버튼 누른 전구 아래쪽
            if (y + 1 != 11) {
                if (board[y + 1][x] == '#') {
                    board[y + 1][x] = 'O';
                } else if (board[y + 1][x] == 'O') {
                    board[y + 1][x] = '#';
                }
            }

            bt(idx + 1, btn_click + 1);

            //bt 다시 버튼 누르기 전으로 원상 복귀
            // 누르는 전구 자기 자신
            if (board[y][x] == '#') {
                board[y][x] = 'O';
            } else if (board[y][x] == 'O') {
                board[y][x] = '#';
            }

            // 버튼 누른 전구 위쪽
            board[y - 1][x] = 'O';

            // 버튼 누른 전구 왼쪽
            if (x - 1 != 0) {
                if (board[y][x - 1] == '#') {
                    board[y][x - 1] = 'O';
                } else if (board[y][x - 1] == 'O') {
                    board[y][x - 1] = '#';
                }
            }

            //버튼 누른 전구 오른쪽
            if (x + 1 != 11) {
                if (board[y][x + 1] == '#') {
                    board[y][x + 1] = 'O';
                } else if (board[y][x + 1] == 'O') {
                    board[y][x + 1] = '#';
                }
            }
            // 버튼 누른 전구 아래쪽
            if (y + 1 != 11) {
                if (board[y + 1][x] == '#') {
                    board[y + 1][x] = 'O';
                } else if (board[y + 1][x] == 'O') {
                    board[y + 1][x] = '#';
                }
            }


        }

    }else{

        //1. 전구 버튼을 누르지 않은 경우
        bt(idx + 1,btn_click);

        //2. 전구 버튼을 누른 경우

        // 버튼 누른 전구
        if (board[y][x] == '#') {
            board[y][x] = 'O';
        } else if (board[y][x] == 'O') {
            board[y][x] = '#';
        }
        // 버튼 누른 전구 왼쪽
        if (x - 1 != 0) {
            if (board[y][x - 1] == '#') {
                board[y][x - 1] = 'O';
            } else if (board[y][x - 1] == 'O') {
                board[y][x - 1] = '#';
            }
        }

        //버튼 누른 전구 오른쪽
        if (x + 1 != 11) {
            if (board[y][x + 1] == '#') {
                board[y][x + 1] = 'O';
            } else if (board[y][x + 1] == 'O') {
                board[y][x + 1] = '#';
            }
        }

        //버튼 누른 전구 아래쪽
        if (board[y + 1][x] == '#') {
            board[y + 1][x] = 'O';
        } else if (board[y+1][x] == 'O') {
            board[y + 1][x] = '#';
        }

        bt(idx + 1, btn_click + 1);

        //bt 버튼 누르기 전으로 원상 복귀
// 버튼 누른 전구
        if (board[y][x] == '#') {
            board[y][x] = 'O';
        } else if (board[y][x] == 'O') {
            board[y][x] = '#';
        }
        // 버튼 누른 전구 왼쪽
        if (x - 1 != 0) {
            if (board[y][x - 1] == '#') {
                board[y][x - 1] = 'O';
            } else if (board[y][x - 1] == 'O') {
                board[y][x - 1] = '#';
            }
        }

        //버튼 누른 전구 오른쪽
        if (x + 1 != 11) {
            if (board[y][x + 1] == '#') {
                board[y][x + 1] = 'O';
            } else if (board[y][x + 1] == 'O') {
                board[y][x + 1] = '#';
            }
        }

        //버튼 누른 전구 아래쪽
        if (board[y + 1][x] == '#') {
            board[y + 1][x] = 'O';
        } else if (board[y+1][x] == 'O') {
            board[y + 1][x] = '#';
        }



    }



}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //(1,1) 부터 (10,10) 까지 입력
    for (int y = 1; y <= 10; y++) {
        string str;
        cin >> str;
        for (int x = 1; x <= 10; x++) {
            board[y][x] = str[x - 1];
        }
    }

    for (int y = 1; y <= 10; y++) {

        for (int x = 1; x <= 10; x++) {
            pos.push_back({x, y});
        }
    }


    bt(0, 0);


    if (ans == NMAX) {
        cout << -1;
    }else
        cout << ans;


    return 0;
}
