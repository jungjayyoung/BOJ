#include <iostream>
#include <algorithm>

#define NMAX 123456789
using namespace std;


// n번 집의 색은 n-1 번 집의 색과 같지 않아야 한다.
// dp[n][0] : 빨간색 비용, dp[n][1] : 초록색 비용, dp[n][2] : 파란색 비용
int dp[1002][3];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    // NMAX 로 초기화
    fill(&dp[0][0], &dp[1001][0], NMAX);


    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        dp[i][0] = a; // 빨간색 비용
        dp[i][1] = b; // 초록색 비용
        dp[i][2] = c; // 파란색 비용

    }




    // 점화식
    // dp[n][a색깔] = dp[n][a 색] + min(dp[n - 1][b 색], dp[n - 1][c 색])
    for (int i = 2; i <= n; i++) {


        for (int k = 0; k < 3; k++) {

            // 빨간색으로 시작할 때
            if (k == 0) {
                dp[i][k] += min(dp[i - 1][1],dp[i -1][2]);
            }


            // 초록색으로 시작할 때
            if (k == 1) {
                dp[i][k] += min(dp[i - 1][0], dp[i - 1][2]);
            }

            // 파란색으로 시작할 때
            if (k == 2) {
                dp[i][k] += min(dp[i - 1][0], dp[i - 1][1]);
            }

        }

    }


    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));


    return 0;
}