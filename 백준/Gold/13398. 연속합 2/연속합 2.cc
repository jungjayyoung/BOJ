#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001][2];// dp[i][0]: 1에서 i 까지에서 가장 큰 연속 합
// dp[i][1]: 1에서 i까지의 수 중에서 하나 제거 후 가장 큰 연속 합
int arr[100001];


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;


    for (int i = 1; i <= n; i++) {
        cin >> arr[i];

    }

    if (n == 1) {
        cout << arr[1];
        return 0;
    }

    int ans = -123456789;

    dp[1][0] = arr[1];
    dp[1][1] = arr[1];

    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        ans = max(ans,max(dp[i][0], dp[i][1]));
    }

    cout << ans;


    return 0;
}