#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;


int n,m;
int dist[500001];
vector<pair<int, int>> v[50001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b, c});
        v[b].push_back({a, c});

    }
    fill(dist, dist + 500001, 123456789);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;

    pq.push({0, 1}); // 가중치, 현재 노드


    dist[1] = 0;
    while (!pq.empty()) {

        int cur = pq.top().second;
        int total = pq.top().first;

        pq.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int weight = v[cur][i].second;

            if (dist[next] > total + weight) {
                dist[next] = total + weight;
                pq.push({dist[next], next});
            }

        }

    }

    cout << dist[n];


    return 0;
}