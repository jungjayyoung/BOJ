#include <iostream>


using namespace std;

int n, m, k, x;
int dp[100002];
int dp2[100002];
int arr[100002];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k >> x;




    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        arr[i] = num;
    }

    dp[1] = x;

    for (int i = 2; i <= n + 1; i++) {
        dp[i] = dp[i - 1] + arr[i - 1];
    }

    int cnt = 0;

    for (int i = 1; i <= n + 1; i++) {
        if (dp[i] < k) {
            cnt++;
            dp2[i] = cnt;
        }else{
            dp2[i] = cnt;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << dp2[b] - dp2[a] << "\n";
    }





    return 0;
}