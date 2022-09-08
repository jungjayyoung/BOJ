#include <iostream>


using namespace std;


int dp[1001];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    dp[1] = 1;
    dp[3] = 1;
    dp[4] = 1;

    for (int i = 5; i <= n; i++) {
        if(!dp[i - 1] || !dp[i - 3] || !dp[i - 4]){
            dp[i] = 1;
        }
    }

    if(dp[n]){
        cout << "SK";
    }else{
        cout << "CY";
    }

    return 0;
}