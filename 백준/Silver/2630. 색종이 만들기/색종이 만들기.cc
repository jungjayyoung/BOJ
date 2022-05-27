#include <iostream>


using namespace std;

int board[400][400];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;


    fill(&board[0][0], &board[201][0], 2);


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int check_size;
    int start_x = 0;
    int start_y = 0;
    int blue_cnt = 0;
    int white_cnt = 0;

    check_size = n;

    while (check_size != 0) {


        bool white_check  = false;
        bool blue_check = false;
        bool two_check = false;



        for (int y = start_y; y < start_y + check_size; y++) {

            for (int x = start_x; x < start_x + check_size; x++) {

                if (board[y][x] == 2) {
                    two_check = true;
                }
                if (board[y][x] == 1) {
                    blue_check = true;
                } else if (board[y][x] == 0) {
                    white_check = true;
                }

            }
        }

        if (!blue_check && white_check && !two_check) {
            white_cnt++;

            for (int y = start_y; y < start_y + check_size; y++) {

                for (int x = start_x; x < start_x + check_size; x++) {

                    board[y][x] = 2;

                }
            }

        }

        if (!white_check && blue_check && !two_check) {
            blue_cnt++;
            for (int y = start_y; y < start_y + check_size; y++) {

                for (int x = start_x; x < start_x + check_size; x++) {
                    board[y][x] = 2;
                }
            }
        }

        start_x = start_x + check_size;


        if (start_x >= n) {
            start_x = 0;
            start_y = start_y + check_size;
        }

        if (start_y >= n) {
            start_x = 0;
            start_y = 0;
            check_size /= 2;
        }




    }

    cout << white_cnt << "\n";
    cout << blue_cnt;


    return 0;
}