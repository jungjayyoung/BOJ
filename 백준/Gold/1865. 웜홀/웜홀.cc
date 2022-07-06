#include <iostream>
#include <vector>

#define INF 270000000

using namespace std;
typedef long long ll;
ll dist[501];

vector<pair<int, int>> v[501];

int n,m,w;
bool check = false;

void bellman_ford(int start, int goal){


    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;

    for (int iter = 1; iter <= n; iter++) {

        for (int cur = 1; cur <= n; cur++) {

            for (pair<int, int> E:v[cur]) {
                int next = E.first, cost = E.second;

                if (dist[next] > dist[cur] + cost) {

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

    int t;

    cin >> t;

    while (t--) {

        cin >> n >> m >> w;

        //도로 정보 입력
        for (int i = 0; i < m; i++) {

            int s, e, t;
            cin >> s >> e >> t;
            v[s].push_back({e, t});
            v[e].push_back({s, t});

        }

        //웜홀 정보 입력
        for (int i = 0; i < w; i++) {

            int s, e, t;
            cin >> s >> e >> t;
            v[s].push_back({e, -t});
        }

        check = false;


        bellman_ford(1, n);

        if (check) {
            cout << "YES" << "\n";
        }else
            cout << "NO" << "\n";


        for (int i = 1; i <= n; i++) {
            v[i].clear();
        }

    }


    return 0;
}
