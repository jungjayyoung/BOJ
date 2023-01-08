#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n;
vector<int> v[1000001];

int dp[1000001][2]; // 1: 현재 노드가 얼리어뎁터인 경우, 0: 현재 어뎁터가 얼리어뎁터가 아닌 경우
int visited[1000001];

void dfs(int cur){

    visited[cur] = 1;
    dp[cur][1] = 1;

    for (int i = 0; i < v[cur].size(); i++) {
        int next = v[cur][i];
        if(visited[next]) continue;
        dfs(next);
        dp[cur][0] += dp[next][1];
        dp[cur][1] += min(dp[next][0], dp[next][1]);
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);

    }

    dfs(1);

    cout << min(dp[1][0], dp[1][1]);


    return 0;
}