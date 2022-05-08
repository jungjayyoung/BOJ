#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int m, n, k;

int visited[101][101];
vector<int> area_size;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt = 1;


void dfs(int x, int y){


    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if (nextx < 0 || nextx > n - 1 || nexty < 0 || nexty > m - 1) {
            continue;
        }

        if (!visited[nexty][nextx]) {

            dfs(nextx, nexty);
            cnt++;

        }
    }


}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> m >> n >> k;


    // 세로길이 m, 가로길이 n
    // (0,0) 부터 (n - 1, m - 1) 만으로 네모칸의 갯수를 셀 수 있다.
    for (int i = 0; i < k; i++) {
        int a_x, a_y, b_x, b_y;

        cin >> a_x >> a_y >> b_x >> b_y;

        for (int y = a_y; y <= b_y - 1; y++) {

            for (int x = a_x; x <= b_x - 1; x++) {

                visited[y][x] = 1;
            }
        }

    }


    for (int y = 0; y <= m - 1; y++) {

        for (int x = 0; x <= n - 1; x++) {
            if (!visited[y][x]) {
                cnt = 1;
                dfs(x, y);
                area_size.push_back(cnt);
            }
        }
    }


    cout << area_size.size() << "\n";

    sort(area_size.begin(), area_size.end());

    for (int i = 0; i < area_size.size(); i++) {
        cout << area_size[i] << " ";
    }

    return 0;
}