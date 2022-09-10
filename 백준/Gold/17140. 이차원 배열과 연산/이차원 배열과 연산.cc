#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int r,c,k;

int board[201][201];
int nums[101];



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> r >> c >> k;


    for (int y = 1; y <= 3; y++) {

        for (int x = 1; x <= 3; x++) {
            cin >> board[y][x];
        }
    }

    if (board[r][c] == k) {
        cout << 0;
        return 0;
    }

    int cnt = 0;

    int row = 3;
    int col = 3;

    bool check = false;

    while (board[r][c] != k && cnt < 100) {

        vector<pair<int, int>> rr[101];
        vector<pair<int, int>> cc[101];
        int next_row = row;
        int next_col = col;

        // r 연산
        if (row >= col) {

            for (int y = 1; y <= row; y++) {
                fill(nums, nums + 101, 0);
                for (int x = 1; x <= col; x++) {
                    nums[board[y][x]]++;
                }

                for (int i = 1; i <= 100; i++) {
                    if (nums[i]) {
                        rr[y].push_back({nums[i], i});//횟수, 숫자
                   }
                }

                sort(rr[y].begin(), rr[y].end());
                next_col = max(next_col, (int)rr[y].size() * 2);

            }

            col = min(next_col,100);
            for (int y = 1; y <= row; y++) {

                int idx = 1;
                for (int x = 0; x < col; x++) {
                    int num;
                    int num_cnt;

                    if (rr[y].size() < col && idx >= rr[y].size() * 2) {
                        num = 0;
                        num_cnt = 0;
                    }else{
                        num = rr[y][x].second;
                        num_cnt = rr[y][x].first;
                    }

                    board[y][idx++] = num;
                    board[y][idx++] = num_cnt;
                }
            }



        // c 연산
        } else {


            for (int x = 1; x <= col; x++) {

                fill(nums, nums + 101, 0);
                for (int y = 1; y <= row; y++) {
                    nums[board[y][x]]++;
                }

                for (int i = 1; i <= 100; i++) {

                    if (nums[i]) {
                        cc[x].push_back({nums[i], i});
                    }
                }
                next_row = max(next_row, (int)cc[x].size() * 2);
                sort(cc[x].begin(), cc[x].end());
            }

            row = min(next_row,100);

            for (int x = 1; x <= col; x++) {

                int idx = 1;
                for (int y = 0; y < row; y++) {

                    int num;
                    int num_cnt;
                    if (cc[x].size() < row && idx >= cc[x].size() * 2) {
                        num = 0;
                        num_cnt = 0;
                    }else{
                        num = cc[x][y].second;
                        num_cnt = cc[x][y].first;
                    }

                    board[idx++][x] = num;
                    board[idx++][x] = num_cnt;
                }

            }


        }

        cnt++;

        if (board[r][c] == k) {
            check = true;
            break;
        }
    }


    if (check) {
        cout << cnt;
    }else{
        cout << -1;
    }

    return 0;
}