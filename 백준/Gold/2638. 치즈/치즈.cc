#include <iostream>


using namespace std;

int n,m;
int board[101][101];
int visited[101][101];
int air_contact_cheese[101][101];
int air_visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void cheese_dfs(int x,int y){

    visited[y][x] = 1;

    int cnt = 0;

    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if(nextx < 0 || nexty < 0 || nextx >= m || nexty >= n) continue;

        if (board[nexty][nextx] == 0 && air_visited[nexty][nextx] == 1) {
            cnt++;
        }

        if(!visited[nexty][nextx] && board[nexty][nextx] == 1) {

            cheese_dfs(nextx, nexty);

        }

    }

    if (cnt >= 2) {
        air_contact_cheese[y][x] = 1;
    }


}

void air_dfs(int x,int y){

    air_visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if(nextx< 0 || nexty < 0 || nextx >= m || nexty >= n) continue;

        if(board[nexty][nextx] == 0 && !air_visited[nexty][nextx]){
            air_dfs(nextx, nexty);
        }

    }


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;

    for(int y = 0; y < n; y++){

        for (int x = 0; x < m; x++) {
            cin >> board[y][x];
        }
    }

    int ans = 0;
    bool check;

    air_dfs(0, 0); // 가장자리 공기 체크

    while(1){
        check = false;
        // 치즈가 다 녹았는지 체크
        for(int y = 0; y < n; y++){

            for (int x = 0; x < m; x++) {
                if(board[y][x] == 1) {
                    check = true;
                }

            }
        }

        if (!check) {
            break;
        }


        fill(&visited[0][0], &visited[n][m], 0);
        //공기에 접촉하는 치즈 dfs로 체크
        for (int y = 0; y < n; y++) {

            for (int x = 0; x < m; x++) {
                if (!visited[y][x] && board[y][x] == 1) {
                    cheese_dfs(x, y);
                }
            }
        }

        // 공기에 접촉하는 치즈 제거 및 air_visited 1 초기화
        for (int y = 0; y < n; y++) {

            for (int x = 0; x < m; x++) {
                if (board[y][x] == 1 && air_contact_cheese[y][x] == 1) {
                    board[y][x] = 0;
                    if(!air_visited[y][x]) {
                        air_dfs(x, y);
                    }
                }
            }
        }
        ans++;

    }

    cout << ans;

    return 0;
}