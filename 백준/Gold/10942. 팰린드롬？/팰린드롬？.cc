#include <iostream>


using namespace std;


bool dp[2001][2001];
int arr[2001];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    fill(&dp[0][0], &dp[2001][0], false);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][i] = true;
    }

    for (int i = 1; i <= n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            dp[i][i + 1] = true;
        }
    }

    for (int i = n - 2; i >= 1; i--) {
        for (int j = i + 2; j <= n; j++) {
            if (arr[i] == arr[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
            }
        }
    }

    int m;
    cin >> m;

    while (m--) {

        int a, b;
        cin >> a >> b;

        if (dp[a][b]) {
            cout << 1 << "\n";
        }else
            cout << 0 << "\n";

    }
    return 0;
}