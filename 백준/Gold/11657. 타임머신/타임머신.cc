#include <iostream>
#include <vector>

#define INF 100000000

typedef long long ll;

using namespace std;


ll dist[501];
int n,m;
vector<pair<int, int>> adj[501];

bool check = false;

void bellman_ford(int start, int goal){

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    check = false;
    for (int iter = 1; iter <= n; iter++) {

        for (int cur = 1; cur <= n; cur++) {

            for (pair<int, int> E: adj[cur]) {
                int next = E.first, cost = E.second;
                if (dist[cur] != INF && dist[next] > dist[cur] + cost) {
                    dist[next] = dist[cur] + cost;
                    if (iter == n) {
                        check = true;
                    }
                }
            }
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});

    }

    bellman_ford(1, n);


    if (check) {
        cout << -1;
    }else{
        for (int i = 2; i <= n; i++) {

            if (dist[i] == INF) {
                cout << -1 << "\n";
            }else
                cout << dist[i] << "\n";
        }
    }



    return 0;
}