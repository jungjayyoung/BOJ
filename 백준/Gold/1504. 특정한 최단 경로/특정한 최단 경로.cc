#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define NMAX 987654321
using namespace std;


int dist[801]; // dist[n]: 1번 부터 n번까지의 최단 거리
int n,e;
vector<pair<int,int>> v[801];
int v1,v2;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> e;


    for (int i = 0; i < e; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    cin >> v1 >> v2;

    fill(dist, dist + n + 1, NMAX);
    dist[1] = 0;
    int ans1 = 0; // (경로 1 -> v1 -> v2 -> n)
    int ans2 = 0; // (경로 1 -> v2 -> v1 -> n)

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq; // 1부터  현재 까지 가중치, 현재 노드


    // 1번 부터 v1,v2 번까지의 최단 경로 구하기
   pq.push({0, 1});

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_weight = pq.top().first;
        pq.pop();

        if(cur_weight > dist[cur_node]) continue;

        for (auto i : v[cur_node]) {
            int weight = i.second;
            int next_node = i.first;
            if(dist[next_node] > cur_weight + weight){
                dist[next_node] = cur_weight + weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    if(dist[v1] == NMAX && dist[v2] == NMAX){
        cout << -1;
        return 0;
    }
    ans1 += dist[v1];
    ans2 += dist[v2];

    // v1번 부터 v2번 까지의 최단 경로 구하기 (= v2 부터 v1)
    fill(dist, dist + n + 1, NMAX);
    dist[v1] = 0;
    pq.push({0, v1});

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_weight = pq.top().first;
        pq.pop();

        if(cur_weight > dist[cur_node]) continue;

        for (auto i : v[cur_node]) {
            int weight = i.second;
            int next_node = i.first;
            if(dist[next_node] > cur_weight + weight){
                dist[next_node] = cur_weight + weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    if(dist[v2] == NMAX){
        cout << -1;
        return 0;
    }
    ans1 += dist[v2];
    ans2 += dist[v2];

    // n번 부터 v1,v2번 까지의 최단 경로 구하기
    fill(dist, dist + n + 1, NMAX);
    dist[n] = 0;
    pq.push({0, n});

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_weight = pq.top().first;
        pq.pop();

        if(cur_weight > dist[cur_node]) continue;

        for (auto i : v[cur_node]) {
            int weight = i.second;
            int next_node = i.first;
            if(dist[next_node] > cur_weight + weight){
                dist[next_node] = cur_weight + weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    if(dist[v1] == NMAX && dist[v2] == NMAX){
        cout << -1;
        return 0;
    }
    ans1 += dist[v2];
    ans2 += dist[v1];

    cout << min(ans1, ans2);
    return 0;
}