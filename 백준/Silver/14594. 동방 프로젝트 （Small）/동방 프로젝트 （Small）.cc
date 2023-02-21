#include <iostream>

using namespace std;


int n, m;
int visited[102];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = x + 1; j <= y; j++) {
            visited[j] = 1;
        }
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++) {

        if (visited[i] == 0) {
            cnt++;
        }
    }

    cout << cnt;


    return 0;
}