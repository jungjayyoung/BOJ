#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[100001];
int visited[100001];
int n, m, r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> r;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    queue<int> q;

    q.push(r);
    visited[r] = 1;
    int cnt = 2;

    while (!q.empty()) {
        int cur = q.front();

        q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            if (!visited[next]) {
                visited[next] = cnt++;
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << visited[i] << "\n";
    }

    return 0;
}