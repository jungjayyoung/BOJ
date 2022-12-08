#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int n, q;
vector<pair<int, int>> v[5001];
int visited[5001];
int cnt;

void bfs(int k,int st){

    queue<int> q;
    q.push(st);
    visited[st] = 1;

    cnt = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int weight = v[cur][i].second;

            if (!visited[next] && weight >= k) {
                visited[next] = 1;
                cnt++;
                q.push(next);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for (int i = 0; i < q; i++) {
        int k, b;
        // k 이상의 가중치를 가지면 포함이 된다.
        cin >> k >> b;
        fill(visited, visited + 5001, 0);
        bfs(k, b);
        cout << cnt << "\n";

    }



}