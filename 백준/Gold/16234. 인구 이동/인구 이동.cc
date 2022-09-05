#include <iostream>
#include <algorithm>


using namespace std;

int board[101][101];
int visited[101][101];
int section_board[101][101];

int n, l, r;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int section_num = 1;
int cnt = 1;
int sum = 0;
bool check = false; // 인구이동이 있을 경우 check = true가 된다.
int section_population[10001];

void dfs(int x, int y){

    visited[y][x] = 1;
    section_board[y][x] = section_num;
    cnt++;
    sum += board[y][x];

    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= n) {
            continue;
        }

        if(!visited[nexty][nextx]){

            int diff = abs(board[y][x] - board[nexty][nextx]);

            if (diff >= l && diff <= r) {
                check = true;
                dfs(nextx, nexty);
            }
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l >> r;


    for (int y = 0; y < n; y++) {

        for (int x = 0; x < n; x++) {

            cin >> board[y][x];

        }
    }


    int ans = 0;
    while(1){

        check = false; // 인구이동이 있을 경우 check = true가 된다.
        section_num = 1;
        fill(&visited[0][0], &visited[101][0], 0);
        fill(section_population, section_population + 10000, 0);
        fill(&section_board[0][0], &section_board[101][0], 0);



        for (int y = 0; y < n; y++) {

            for (int x = 0; x < n; x++) {
                cnt = 0;
                sum = 0;
                if (!visited[y][x]) {
                    dfs(x, y);
                    section_population[section_num] = sum / cnt;
                    section_num++;
                }
            }
        }
        section_num = 1;
        for (int y = 0; y < n; y++) {

            for (int x = 0; x < n; x++) {

                board[y][x] = section_population[section_board[y][x]];

            }
        }

        

        if(!check){
            break;
        }
        ans++;

    }

    cout << ans;


    return 0;
}