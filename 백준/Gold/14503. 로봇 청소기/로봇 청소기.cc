#include <iostream>



using namespace std;

int board[51][51];
int visited[51][51]; //청소 여부 판단
int n,m;
int xx,yy,d;
bool done = false;
int clean = 0;
// 0: 북,  1: 동,   2: 남,   3: 서
void solve(int x, int y, int dir, int cnt){

    if(done) return;

    if (!visited[y][x] && board[y][x] != 1) {
        visited[y][x] = 1;
        clean++;
    }


    if (cnt == 4) {
        if (dir == 0) {
            if ((y + 1 < n-1) && board[y + 1][x] != 1) {

                solve(x, y + 1, 0, 0);
            } else {
                done = true;
                return;
            }

        } else if (dir == 1) {

            if ((x - 1 > 0) && board[y][x - 1] != 1 ){

                solve(x - 1, y, 1, 0);
            } else {
                done = true;
                return;
            }
        } else if (dir == 2) {

            if ((y - 1 > 0) && board[y - 1][x] != 1) {

                solve(x, y - 1, 2, 0);
            } else {
                done = true;
                return;
            }
        } else if (dir == 3) {
            if ((x + 1 < m - 1) && board[y][x + 1] != 1) {

                solve(x + 1, y, 3, 0);
            } else {
                done = true;
                return;
            }
        }
    }
    if(done) return;

    if (dir == 0) {
        if ((x - 1 > 0) && board[y][x - 1] != 1 && !visited[y][x - 1]) {

            solve(x - 1, y, 3, 0);
        }else{
            solve(x , y, 3, cnt+1);
        }

    } else if (dir == 1) {
        if ((y - 1 > 0 ) && board[y - 1][x] != 1 && !visited[y - 1][x]) {

            solve(x , y - 1, 0, 0);
        }else{
            solve(x , y, 0, cnt+1);
        }

    } else if (dir == 2) {

        if ((x + 1 < m - 1) && board[y][x + 1] != 1 && !visited[y][x + 1]) {

            solve(x + 1, y, 1, 0);
        }else{
            solve(x , y, 1, cnt+1);
        }
    } else if (dir == 3) {

        if ((y + 1 < n-1) && board[y+1][x] != 1 && !visited[y+1][x]) {
            solve(x, y + 1, 2, 0);
        }else{
            solve(x , y, 2, cnt+1);
        }
    }



}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;

    cin >> yy >> xx >> d;

    for (int y = 0; y < n; y++) {

        for (int x = 0; x < m; x++) {

            cin >> board[y][x];
        }
    }


    solve(xx , yy , d, 0);

    cout << clean;
    return 0;
}