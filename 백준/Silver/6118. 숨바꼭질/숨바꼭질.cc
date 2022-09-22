#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[20001];
int visited[20001];
int ans = 0;
int ans_cnt = 0;
int ans_idx = -1;
void bfs(){

    queue<pair<int,int>> q;

    q.push({1, 0});
    visited[1] = 1;

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (ans < cnt) {
            ans = cnt;
            ans_cnt = 1;
            ans_idx = cur;
        }else if (ans == cnt) {
            ans_idx = min(ans_idx, cur);
            ans_cnt++;
        }

        for (auto i: v[cur]) {

            if (!visited[i]) {
                visited[i] = 1;
                q.push({i, cnt + 1});
            }
        }


    }

}
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
    
    bfs();
    
    cout << ans_idx << " " << ans << " " << ans_cnt;
    
    return 0;
}