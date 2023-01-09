#include <iostream>


using namespace std;

int n;
// 연속된 약을 떼어 먹을때: 2가지 경우
// 양 사이드를 먹고 점심약을 먹을 때: 1가지 경우
int dp[16];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    dp[1] = 2;

    for (int i = 2; i <= 15; i++) {
        dp[i] = dp[i - 1] * 2 + dp[i - 1];
    }

    cout << dp[n];


    return 0;
}