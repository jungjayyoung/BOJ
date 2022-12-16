#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, m, r;
vector<ll> v[100001];
ll visited[100001];
ll order[100001];
ll sum = 0;
int cnt = 1;

void dfs(int cur,int depth){

    visited[cur] = depth;
    order[cur] = cnt++;


    for (int i = 0; i < v[cur].size(); i++) {
        int next = v[cur][i];
        if (visited[next] == -1) {
            dfs(next, depth + 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> r;

    for (int i = 0; i < m; i++) {
        int d, t;
        cin >> d >> t;
        v[d].push_back(t);
        v[t].push_back(d);
    }

    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    fill(visited, visited + n + 1, -1);

    dfs(r, 0);

    for (int i = 1; i <= n; i++) {
        //cout << visited[i] << "\n";
        if(order[i] == 0 || visited[i] == -1) continue;
        sum += order[i] * visited[i];
    }

    cout << sum;

    return 0;
}