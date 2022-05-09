#include <iostream>



using namespace std;

int cheese[101][101];
int no_cheese[101][101];
int visited[101][101];
int air[101][101];
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


void dfs_cheese(int x, int y){

    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) {
            continue;
        }

        if (air[nexty][nextx] == 1) {
            no_cheese[y][x] = 1;
            break;
        }
    }


}

void dfs_air(int x, int y){


    visited[y][x] = 1;
    air[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) {
            continue;
        }

        if (!cheese[nexty][nextx] && air[nexty][nextx] == 0) {
            dfs_air(nextx, nexty);
        }
    }

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;



    for (int y = 0; y < m; y++) {

        for (int x = 0; x < n; x++) {
            cin >> cheese[y][x];
        }
    }

    // 외부 공기와 접촉한 공간은 air[y][x] 가 1이 된다.
    dfs_air(0,0);

    int day = 0;
    int pre_cheese_num = 0;
    while (1){

        bool check = false;
        fill(&visited[0][0], &visited[101][0], 0);
        pre_cheese_num = 0;

        // 1. 이전 치즈 값 pre_cheese_num 저장하기
        for (int y = 0; y < m; y++) {

            for (int x = 0; x < n; x++) {


                if (cheese[y][x]) {
                    pre_cheese_num++;
                    check = true;
                }
            }
        }


        if(!check){
            break;
        }

        //치즈를 전부 탐색하면서 없어질 치즈 no_cheese[y][x]를 1로 만들어 준다.
        for (int y = 0; y < m; y++) {

            for (int x = 0; x < n; x++) {
                if (!visited[y][x] && cheese[y][x]) {
                    visited[y][x] = 1;
                    dfs_cheese(x, y);
                }
            }
        }

        // 치즈판 업데이트, 치즈(cheese[y][x] = 0 으로) 없애고 air 1로 만들기
        for (int y = 0; y < m; y++) {

            for (int x = 0; x < n; x++) {
                if (no_cheese[y][x]) {
                    cheese[y][x] = 0;
                    air[y][x] = 1;
                }
            }
        }

        // 치즈가 없어진 곳들부터 다시 외부 공기 접촉 air을 업데이트
        for (int y = 0; y < m; y++) {

            for (int x = 0; x < n; x++) {
                if (no_cheese[y][x]) {
                    dfs_air(x, y);
                }
            }
        }

        day++;
        check = false;
        // 2. 치즈가 다 없어졌는지 체크
        for (int y = 0; y < m; y++) {

            for (int x = 0; x < n; x++) {

                if (cheese[y][x]) {
                    check = true;
                }
            }

        }

        if(!check){
            break;
        }


    }


    cout << day << "\n";
    cout << pre_cheese_num;


    return 0;
}