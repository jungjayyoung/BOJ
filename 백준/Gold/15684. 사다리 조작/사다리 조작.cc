#include <iostream>
#include <algorithm>

using namespace std;
int n, m, h;
int ans = 987;
int visited[11][31]; // visited[a][b] a와 a+1이 b번째 가로선으로 연결됐다.

// https://yabmoons.tistory.com/47 참고했다.
// 너무나도 아름다운 사다리 게임 코드... 난 이게 왜 생각이 안났지...?
bool ladder_game(){

    for (int i = 1; i <= n; i++) {

        int cur_col = i;
        for (int j = 1; j <= h; j++) {

            if (visited[cur_col][j] == 1) {
                cur_col = cur_col + 1;
            } else if (visited[cur_col - 1][j] == 1) {
                cur_col = cur_col - 1;
            }
        }
        if (cur_col != i) {
            return false;
        }
    }

    return true;

}

void bt(int idx, int cnt){

    if(cnt >= 4){

        return;
    }

    if (ladder_game()) {
        ans = min(ans, cnt);
        return;
    }

    for (int col = 1; col <= n - 1; col++) {

        for (int row = idx; row <= h; row++) {


            if(visited[col][row]) continue;
            if (col != n - 1) {
                if (visited[col + 1][row]) continue;
            }
            if (col != 1) {
                if (visited[col - 1][row]) continue;
            }

            visited[col][row] = 1;
            bt(row, cnt + 1);
            visited[col][row] = 0;

        }
    }


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //사다리 게임을 어떻게 만들까?


    //세로선 갯수, 현재 연결된 가로선 갯수, 세로선 마다 가로선 넣을 수 있는 위치 갯수
    cin >> n >> m >> h;


    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        visited[b][a] = 1;
    }


    bt(1, 0);

    if (ans == 987) {
        cout << -1;
    }else
        cout << ans;





    return 0;
}