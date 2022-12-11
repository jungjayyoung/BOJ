#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, r, q;

vector<int> v[100001];
int dp[100001];
int visited[100001];

int dfs(int cur){

    dp[cur] = 1;

    for (int i = 0; i < v[cur].size(); i++) {
        int next = v[cur][i];
        if (!visited[next]) {
            visited[next] = 1;
            dp[cur] = dp[cur] + dfs(next);
        }

    }

    return dp[cur];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    visited[r] = 1;
    dfs(r);

    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;
        cout << dp[num] << "\n";
    }

}