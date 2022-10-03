#include <iostream>


using namespace std;


int w,h;

int board[501][501];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w;


    for (int i = 0; i < w; i++) {
        int num;
        cin >> num;

        for (int y = 0; y < num; y++) {
            board[y][i] = 1;
        }
    }

    int ans = 0;
    for (int y = 0; y < h; y++) {
        bool check = false;
        int cnt = 0;

        for (int x = 0; x < w; x++) {

            if (board[y][x] == 1 && !check) {
                cnt = 0;
                check = true;

            } else if (board[y][x] == 1 && check) {
                ans += cnt;
                cnt = 0;
            }

            if (board[y][x] == 0 && check) {
                cnt++;
            }

        }
    }




    cout << ans;
    return 0;
}