#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> vv;

int board[6][6];
int visited[6][6];

bool bingo(){


    int cnt = 0;

    // 가로 빙고 개수 체크
    for (int y = 1; y <= 5; y++) {
        bool check = false;
        for (int x = 1; x <= 5; x++) {
            if (visited[y][x] == 0) {
                check = true;
                break;
            }
        }
        if (!check) {
            cnt++;
        }
    }

    // 세로 빙고 개수 체크
    for (int x = 1; x <= 5; x++) {
        bool check = false;
        for (int y = 1; y <= 5; y++) {
            if (visited[y][x] == 0) {
                check = true;
                break;
            }
        }
        if (!check) {
            cnt++;
        }
    }

    if (visited[1][1] && visited[2][2] && visited[3][3] && visited[4][4] && visited[5][5]) {
        cnt++;
    }

    if (visited[5][1] && visited[4][2] && visited[3][3] && visited[2][4] && visited[1][5]) {
        cnt++;
    }


    if(cnt >= 3) return true;

    return false;



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    for (int y = 1; y <= 5; y++) {

        for (int x = 1; x <= 5; x++) {
            cin >> board[y][x];
        }
    }

    for (int y = 1; y <= 5; y++) {

        for (int x = 1; x <= 5; x++) {
            int num;
            cin >> num;
            vv.push_back(num);
        }
    }


    for (int i = 0; i < vv.size(); i++) {

        int cur = vv[i];
        bool check = false;
        for (int y = 1; y <= 5; y++) {
            for (int x = 1; x <= 5; x++) {

                if (board[y][x] == cur) {

                    visited[y][x] = 1;

                    if (bingo()) {
                        cout << i + 1;
                        return 0;
                    }

                    check = true;
                    break;
                }
            }

            if (check) {
                break;
            }
        }

    }


    return 0;
}