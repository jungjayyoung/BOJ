#include <iostream>
#include <algorithm>
#define NO_ROAD 123456789

using namespace std;

int n,m;

int bus[101][101];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fill(&bus[0][0], &bus[101][0], NO_ROAD);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        bus[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;

        bus[a][b] = min(bus[a][b], c);

    }

    // 중간 노드가 될 노드 번호를 for문 가장 바깥의 k로 잡는다

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                bus[i][j] = min(bus[i][j], bus[i][k] + bus[k][j]);

            }
        }
    }

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {

            if (bus[i][j] == NO_ROAD) {
                cout << 0 << " ";
            }else{
                cout << bus[i][j] << " ";
            }
        }
        cout << "\n";
    }


    return 0;
}