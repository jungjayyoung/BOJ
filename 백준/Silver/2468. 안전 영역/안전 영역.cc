#include <iostream>
#include <algorithm>


using namespace std;


int board[101][101];
int visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n;
int ans = 0;
int max_height = -1;
int cnt = 0;
bool check = false;
void visited_clear(int num){

    for (int i = 0; i < num; i++) {

        for (int j = 0; j < num; j++) {
            visited[i][j] = 0;
        }
    }


}
void dfs(int x, int y, int height){


    if(board[y][x] <= height) return;

    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if(nextx < 0 || nextx >= n || nexty < 0 || nexty >= n) {
            continue;
        }

        if (!visited[nexty][nextx]) {
            if(!check){
                cnt++;
                check = true;
            }
            dfs(nextx, nexty, height);
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
            max_height = max(max_height, board[y][x]);

        }
    }


    for(int i=0;i<=max_height;i++){


        visited_clear(n);
        check = false;
        cnt = 0;
        for (int yy = 0; yy < n; yy++) {
            for (int xx = 0; xx < n; xx++) {
                check = false;
                if(visited[yy][xx])continue;
                dfs(xx, yy, i);

            }
        }

        ans = max(ans, cnt);
    }


    cout << ans;

    return 0;
}