#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int n, m;

int visited[1001][1001];
char map[1001][1001];
int idx_cnt[1000001];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int num = 0;
int cnt;

void dfs(int x, int y,int idx){

    visited[y][x] = idx + 1;



    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx <0 || ny < 0 || nx >=m || ny >= n) continue;

        if (!visited[ny][nx] && map[ny][nx] == '0') {
            cnt++;
            dfs(nx, ny, idx);
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;


    for (int y = 0; y < n; y++) {

        string str;
        cin >> str;
        for (int x = 0; x < m; x++) {
            map[y][x] = str[x];
        }
    }

    for (int y = 0; y < n; y++) {

        for (int x = 0; x < m; x++) {

            if (map[y][x] == '0' && visited[y][x] == 0) {
                cnt = 1;

                dfs(x, y, num);
                idx_cnt[num] = cnt;
                num++;
            }

        }
    }

    for (int y = 0; y < n; y++) {

        for (int x = 0; x < m; x++) {

            if (map[y][x] == '1') {
                int cntt = 1;
                vector<int> v;
                v.clear();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx <0 || ny <0 || nx >= m || ny >= n) continue;

                    if (map[ny][nx] == '0') {
                        int k = visited[ny][nx];
                        v.push_back(k);
                    }

                }

                sort(v.begin(), v.end());

                if (!v.empty()) {
                    cntt += idx_cnt[v[0] - 1];
                }

                for (int i = 1; i < v.size(); i++) {
                    if (v[i - 1] != v[i]) {
                        cntt += idx_cnt[v[i] - 1];
                    }
                }
                cout << cntt % 10;
            }else{
                cout << 0;
            }

        }
        cout << "\n";
    }


    return 0;
}