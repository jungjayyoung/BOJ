#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int len;

int board[22][22];
bool visited[22];
int ans[22];
int minn = 987654321;
void bt(int idx){

    if (idx == len + 1) {

        int team1 = 0;
        int team2 = 0;

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= n; j++) {

                if (visited[j] && visited[i]) {
                    team1 += board[i][j];
                }

                if (!visited[j] && !visited[i]) {
                    team2 += board[i][j];
                }

            }

        }

        minn = min(minn, abs(team1 - team2));

        return;
    }


    for (int i = 1; i <= n; i++) {

        if (idx >= 2 && ans[idx - 1] > i) continue;
        if (!visited[i]) {
            visited[i] = 1;
            ans[idx] = i;
            bt(idx + 1);
            visited[i] = 0;

        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);



    cin >> n;

    len = n / 2;
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {

            cin >> board[i][j];
        }
    }

    bt(1);

    cout << minn;
    return 0;
}