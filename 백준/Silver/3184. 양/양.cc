#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int r,c;
char board[251][251];
int visited[251][251];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int wolf,sheep;

void dfs(int x,int y){

    visited[y][x] = 1;

    if(board[y][x] == 'v') wolf++;
    else if(board[y][x] == 'o') sheep++;

    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if(nextx < 0 || nexty < 0 || nextx >= c || nexty >= r) continue;

        if(!visited[nexty][nextx] && board[nexty][nextx] != '#'){
            if(board[nexty][nextx] == 'v'){

            }else if(board[nexty][nextx] == 'o'){

            }
            dfs(nextx,nexty);
        }

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;

    for (int y = 0; y < r; y++) {

        for (int x = 0; x < c; x++) {
            cin >> board[y][x];
        }
    }

    int total_wolf = 0;
    int total_sheep = 0;

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if(!visited[y][x] && board[y][x] != '#'){
                wolf = 0;
                sheep = 0;
                dfs(x, y);
                if(wolf < sheep){
                    total_sheep += sheep;
                }else{
                    total_wolf += wolf;
                }
            }
        }
    }

    cout << total_sheep << " " << total_wolf;

    return 0;
}