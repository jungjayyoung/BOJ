#include <iostream>
#include <algorithm>

using namespace std;

int dp[2001];
int attack[2001];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    // 가장 긴 감소하는 수열


    for (int i = 0; i < n; i++) {
        cin >> attack[i];
        dp[i] = 1; // 처음엔 길이가 다 똑같다.
    }


    int ans = 1;
    for (int i = 0; i < n; i++) {

        int cur = attack[i];
        for (int j = 0; j < i; j++) {

            if (cur < attack[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(ans, dp[i]);

    }


    cout << n - ans;

    return 0;
}