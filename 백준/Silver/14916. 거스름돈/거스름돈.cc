#include <iostream>


using namespace std;

int dp[100001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;
    for (int i = 6; i <= 100000; i++) {
        if (dp[i - 5] != 0){
            dp[i] = dp[i-5] + 1;
        } else if (dp[i - 2] != 0) {
            dp[i] = dp[i-2] + 1;
        }
    }

    if(dp[n]){
        cout << dp[n];
    }else{
        cout << -1;
    }


    return 0;
}