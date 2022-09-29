#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[501];

int visited[501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n >> m;


    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);

    }


    queue<pair<int,int>> q;

    q.push({1, 0});

    int ans = 0;
    while (!q.empty()) {

        int cur = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if(cnt >= 3) continue;

        if(cur != 1) ans++;

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];

            if (!visited[next]) {
                visited[next] = 1;
                q.push({next, cnt + 1});
            }

        }


    }

    cout << ans;

    return 0;
}