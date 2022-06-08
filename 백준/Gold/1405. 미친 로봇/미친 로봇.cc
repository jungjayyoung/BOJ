#include <iostream>


using namespace std;

int visited[300][300];

int num;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
double dpr[4];
double ans = 0;

void dfs(int x, int y,int cnt, double pr){

    if (cnt >= num) {

        ans += pr;
        return;
    }

    for (int i = 0; i < 4; i++) {
        //0: 서, 1: 북, 2: 동, 3: 남

        int nextx = dx[i] + x;
        int nexty = dy[i] + y;


        if (!visited[nexty][nextx]) {
            visited[nexty][nextx] = 1;
            dfs(nextx, nexty, cnt + 1, pr * dpr[i]);
            visited[nexty][nextx] = 0;

        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> num;
    for (int i = 0; i < 4; i++) {
        int a;
        cin >> a;
        dpr[i] = (double)a / 100;

    }


    fill(&visited[0][0], &visited[300][0], 0);

    visited[150][150] = 1;
    dfs(150, 150, 0, 1);

    cout.precision(10);
    cout << ans;


    return 0;

}