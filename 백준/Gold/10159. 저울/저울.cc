#include <iostream>
#define NMAX 12345678

using namespace std;


int n, m;
int dist[101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    fill(&dist[0][0], &dist[101][0], NMAX);

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;

    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {

        int cnt = 0;
        for (int j = 1; j <= n; j++) {

            if (dist[i][j] != NMAX || dist[j][i] != NMAX) {
                cnt++;
            }

        }

        cout << n - cnt << "\n";

    }

}