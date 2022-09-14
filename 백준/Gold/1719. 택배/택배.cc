#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m;
int dist[201];
int trace[201];

vector<pair<int,int>> v[201];

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

    fill(dist, dist + n + 1, INT_MAX);

    for (int i = 1; i <= n; i++) {

        fill(dist, dist + n + 1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 가중치, 현재 노드

        dist[i] = 0;
        pq.push({0, i});

        while (!pq.empty()) {

            int weight = pq.top().first;
            int cur_node = pq.top().second;

            pq.pop();


            for (auto i: v[cur_node]) {
                int next_weight = i.second;
                int next_node = i.first;

                if (dist[next_node] > weight + next_weight) {
                    dist[next_node] = weight + next_weight;
                    trace[next_node] = cur_node;
                    pq.push({dist[next_node], next_node});

                }

            }
        }

        // 시작노드는 i 이다
        // 도착 노드가 j 가 된다.
        for (int j = 1; j <= n; j++) {

            if(i == j)
                cout << "-" << " ";
            else if(trace[j] == i){
                cout << j << " ";
            }else{
                // i 노드에서 가장 가까운 거치는 노드 탐색
                // trace[index] = i 일 때가 i에서 index로 가는 길이므로
               // 위 조건을 만족하는 index가 가장 먼저 거치는 수

                int idx = j;
                while(1){

                    if(trace[idx] == i){
                        cout << idx << " ";
                        break;
                    }else{
                        idx = trace[idx];
                    }

                }
            }
        }
        cout << "\n";
    }





    return 0;
}