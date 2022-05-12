#include <iostream>
#include <algorithm>
#define NO_ROAD 1234567


using namespace std;

int item[101];
int location[101][101];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    fill(&location[0][0], &location[101][0], NO_ROAD);

    for (int i = 1; i <= n; i++) {
        cin >> item[i];
        location[i][i] = 0;
    }


    for (int i = 0; i < r; i++) {
        int a,b,l;
        cin >> a >> b >> l;
        location[a][b] = l;
        location[b][a] = l;
    }

    //플로이드 와샬
    for (int k = 1; k <= n; k++) {

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= n; j++) {

                location[i][j] = min(location[i][j], location[i][k] + location[k][j]);

            }
        }
    }


    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {

            if (location[i][j] <= m) {
                sum += item[j];
            }

        }
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}