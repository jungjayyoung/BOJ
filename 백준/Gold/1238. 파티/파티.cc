#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;





vector<pair<int,int>> v[1001];
int dist[1001][1001];


int n,m,x;

void solve(int num){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,num});

    while (!pq.empty()) {

        auto cur = pq.top();
        pq.pop();

        if(dist[cur.second][num] < cur.first) continue;



        for (auto nxt: v[cur.second]) {
            if(dist[nxt.first][num] > dist[cur.second][num] + nxt.second){
                dist[nxt.first][num] = dist[cur.second][num] + nxt.second;
                pq.push({dist[nxt.first][num],nxt.first});
            }
        }

    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >>x;


    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }

    fill(&dist[0][0],&dist[1001][0],INT_MAX);


    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        solve(i);
    }


    int result = -1;
    for (int i = 1; i <= n; i++) {
        result = max(result, dist[i][x] + dist[x][i]);
    }

    cout << result;
    return 0;
}