#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int n, m;
string map[501][501];
int total = 0;
int ans = 0;

int row[501];
int col[501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
            for (int i = 0; i < map[y][x].size(); i++) {
                if (map[y][x][i] == '9') {
                    total++;
                    row[y]++;
                }
            }
        }
        ans = max(ans, row[y]);
    }

    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            for (int i = 0; i < map[y][x].size(); i++) {
                if (map[y][x][i] == '9') {
                    col[x]++;
                }
            }
        }
        ans = max(ans, col[x]);
    }

    cout << total - ans;


    return 0;
}