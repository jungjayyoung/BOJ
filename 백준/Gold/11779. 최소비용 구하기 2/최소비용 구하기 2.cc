#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define NMAX 987654321
using namespace std;


int n, m;
int s, e;
vector<pair<int, int>> v[1001];
vector<int> ans;
int ans_cost;


int dist[1001]; // 처음 거리에서부터의 거리를 저장할 배열
int route[1001]; // route[a] = b; a정점에 도착하기 위한 이전 정점은 b입니다.

// c++ 은 최대힙이기 때문에 최소힙으로 만들려면 이렇게 비교연산자를 만들어줘야 한다.
struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    fill(dist, dist + 1001,NMAX);


    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;


    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }


    cin >> s >> e;


    dist[s] = 0;


    pq.push({s, 0});


    while (!pq.empty()) {

        int cur = pq.top().first;
        int cur_cost = pq.top().second;

        pq.pop();
        if(dist[cur] < cur_cost) continue;

        for (int i = 0; i < v[cur].size(); i++) {
            int nx = v[cur][i].first;
            int ncost = v[cur][i].second;

            if (dist[nx] > cur_cost + ncost) {
                route[nx] = cur;
                dist[nx] = cur_cost + ncost;
                pq.push({nx, dist[nx]});
            }

        }

    }


    ans_cost = dist[e];
    cout << ans_cost << "\n";




    int cur = e;
    int nx;
    ans.push_back(e);


    while (cur != s) {


        nx = route[cur];
        ans.push_back(nx);
        cur = nx;

    }

    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }


    return 0;
}