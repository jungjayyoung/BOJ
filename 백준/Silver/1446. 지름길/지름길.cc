#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define NMAX 98765432
using namespace std;

int n, d;
// 지름길 : a에서 b로 가는 비용

vector<pair<int,int>> v[10001];
int dp[10001];



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> d;

    fill(dp, dp + 10000, NMAX);


    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        v[b].push_back({a, c}); //시작, 거리
    }

    dp[0] = 0;
    for (int i = 1; i <= d; i++) {
        if (v[i].empty()) {
            dp[i] = dp[i-1] + 1;
        }else{
            for (int j = 0; j < v[i].size(); j++) {
                dp[i] = min(dp[i], min(dp[i - 1] + 1, dp[v[i][j].first] + v[i][j].second));
            }

        }
    }

    cout << dp[d];
    return 0;
}