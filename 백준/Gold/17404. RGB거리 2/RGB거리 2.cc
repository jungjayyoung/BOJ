#include <iostream>
#include <algorithm>
#define NMAX 987654321
using namespace std;


int red[1001];
int green[1001];
int blue[1001];

int dp[1001][3]; // dp[i][j]: 처음 집 색이 j 일 때 i번째 까지의 최소 비용

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    fill(&dp[0][0], &dp[1001][0], NMAX);
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        red[i] = a;
        green[i] = b;
        blue[i] = c;
    }



    int ans = NMAX;
    for (int k = 0; k < 3; k++) {

        dp[0][0] = NMAX;
        dp[0][1] = NMAX;
        dp[0][2] = NMAX;
        if(k == 0)
            dp[0][k] = red[0];
        else if(k == 1){
            dp[0][k] = green[0];
        }else if(k == 2){
            dp[0][k] = blue[0];
        }

        for (int i = 1; i < n; i++) {

            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + red[i];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + green[i];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + blue[i];

        }

        for (int j = 0; j < 3; j++) {

            if(k ==j) continue;

            ans = min(ans, dp[n - 1][j]);

        }

    }



    cout << ans;

    return 0;
}