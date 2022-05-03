#include <iostream>
#include <vector>

using namespace std;
int n,l;
vector<int> col[101];
vector<int> row[101];
int board[101][101];
int board2[101][101];
bool is_col[101];
bool is_row[101];

vector<pair<int, int>> r[101];
vector<pair<int, int>> c[101];


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> l;


    for (int y = 0; y < n; y++) {

        for (int x = 0; x < n; x++) {
            cin >> board[y][x];
            board2[x][y] = board[y][x];

        }
    }

    //1. 행 부터 체크, 인덱스는 0부터 시작
    fill(&is_row[0], &is_row[101], true);
    fill(&is_col[0], &is_col[101], true);

    for (int y = 0; y < n; y++) {

        int cnt = 1;
        int cur = board[y][0];
        bool check =false;
        for (int x = 1; x < n; x++) {

            if (abs(board[y][x] - cur) >= 2) {
                is_row[y] = false;
                break;
            }
            if (board[y][x] == cur) {
                cur = board[y][x];
                cnt++;
            }

            // 내리막길
            if (cur > board[y][x]) {

                int idx = x;
                int num = 1;
                int height = board[y][x];



                while (num <= l) {

                    if (idx >= n) {
                        check = true;
                        break;
                    }
                    if (height != board[y][idx]) {
                        check = true;
                        break;
                    }

                    num++;
                    idx++;
                }

                if (check) {
                    is_row[y] = false;
                }
                cnt = 0;
                cur = board[y][x + l - 1];
                x = x + l - 1;

            }
            if(check){
                break;
            }

            //오르막길
            if (cur < board[y][x]) {

                if (cnt >= l) {
                    cnt = 1;
                    cur = board[y][x];

                }else{
                    is_row[y] = false;
                    break;

                }


            }

        }
    }

    for (int y = 0; y < n; y++) {

        int cnt = 1;
        int cur = board2[y][0];
        bool check =false;
        for (int x = 1; x < n; x++) {

            if (abs(board2[y][x] - cur) >= 2) {
                is_col[y] = false;
                break;
            }
            if (board2[y][x] == cur) {
                cur = board2[y][x];
                cnt++;
            }

            // 내리막길
            if (cur > board2[y][x]) {

                int idx = x;
                int num = 1;
                int height = board2[y][x];



                while (num <= l) {

                    if (idx >= n) {
                        check = true;
                        break;
                    }
                    if (height != board2[y][idx]) {
                        check = true;
                        break;
                    }

                    num++;
                    idx++;
                }

                if (check) {
                    is_col[y] = false;
                }
                cnt = 0;
                cur = board2[y][x + l - 1];
                x = x + l - 1;

            }
            if(check){
                break;
            }

            //오르막길
            if (cur < board2[y][x]) {

                if (cnt >= l) {
                    cnt = 1;
                    cur = board2[y][x];

                }else{
                    is_col[y] = false;
                    break;

                }


            }

        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (is_row[i]) {
            //cout << i << "\n";
            ans++;
        }
    }

   // cout << "\n";
    for (int i = 0; i < n; i++) {
        if (is_col[i]) {
            //cout << i << "\n";
            ans++;
        }
    }

    cout << ans;


    return 0;
}