#include <iostream>
#include <vector>
#include <algorithm>

#define NMAX 9876543210

typedef long long ll;
using namespace std;
int v,e;

vector<pair<pair<ll,ll>,ll>> road;

ll dist[401][401];
ll ans = NMAX;
ll sum = 0;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    fill(&dist[0][0], &dist[401][0], NMAX);
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        road.push_back({{a, b}, c});
        dist[a][b] = c;
    }



    for (int k = 1; k <= v; k++) {

        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }


    for (int i = 1; i <= v; i++) {
        if (dist[i][i] != NMAX) {
            ans = min(ans, dist[i][i]);
        }
    }

    if (ans != NMAX) {
        cout << ans;
    }else{
        cout << -1;
    }


    return 0;
}