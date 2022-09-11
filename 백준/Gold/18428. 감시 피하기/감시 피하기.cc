#include <iostream>


using namespace std;

int n;

char board[10][10];
int visited[10][10];
bool check = false;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void patrol(int x,int y){



    for (int i = 0; i < 4; i++) {

        for (int k = 1; k < n; k++) {
            int nextx = x + dx[i] * k;
            int nexty = y + dy[i] * k;

            if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n) {
                break;
            }

            if(board[nexty][nextx] == 'O') break;

            if(board[nexty][nextx] == 'S'){
                check = true;
                break;
            }

        }

        if(check)
            break;

    }

}

void bt(int cnt){

    if (cnt >= 3) {

        check = false;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (board[y][x] == 'T') {
                    patrol(x, y);
                    if(check)
                        return;
                }
            }
        }

        if (!check) {
            cout << "YES";
            exit(0);
        }


        return;
    }

    for (int y = 0; y < n; y++) {

        for (int x = 0; x < n; x++) {
            if(!visited[y][x] && board[y][x] == 'X'){
                visited[y][x] = 1;
                board[y][x] = 'O';
                bt(cnt + 1);
                board[y][x] = 'X';
                visited[y][x] = 0;
            }
        }
    }


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;

    for (int y = 0; y < n; y++) {

        for (int x = 0; x < n; x++) {
            cin >> board[y][x];
        }
    }


    bt(0);

    cout << "NO";
    return 0;
}