#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int n,m,r,c,l;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int visited[51][51];
int board[51][51];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;

    cin >> t;


    for(int j = 1; j <=t; j++){

        cin >> n >> m >> r >> c >> l; // 세로,가로


        fill(&visited[0][0], &visited[51][0], 0);
        queue<pair<pair<int,int>,int>> q;

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                cin >> board[y][x];
                if (y == r && x == c) {
                    q.push({{x, y}, 1});
                    visited[y][x] = 1;
                }
            }
        }

        
        while (!q.empty()) {

            int curx = q.front().first.first;
            int cury = q.front().first.second;
            int cnt = q.front().second;
            int type = board[cury][curx];

            q.pop();
            
            for (int i = 0; i < 4; i++) { // 좌,하,우,상

                if(type == 2 && (i == 0 || i == 2)) continue;
                if(type == 3 && (i == 1 || i == 3)) continue;
                if(type == 4 && (i == 0 || i == 1)) continue;
                if(type == 5 && (i == 0 || i == 3)) continue;
                if(type == 6 && (i == 2 || i == 3)) continue;
                if(type == 7 && (i == 1 || i == 2)) continue;

                int nx = curx + dx[i];
                int ny = cury + dy[i];
                int np = board[ny][nx];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

                if(visited[ny][nx]) continue;
                if(np == 0) continue;

                if (i == 0) { // 좌
                    if(type == 1 || type == 3 || type == 6 || type == 7){
                        if(np == 2 || np == 6 || np == 7) continue;
                    }
                }else if(i == 1){ // 하

                    if(type == 1 || type == 2 || type == 5 || type == 6){
                        if(np == 3 || np == 5 || np == 6) continue;
                    }

                }else if(i == 2){ // 우
                    if(type == 1 || type == 3 || type == 4 || type == 5){
                        if(np == 2 || np == 4 || np == 5) continue;
                    }
                }else if(i == 3){ // 상
                    if(type == 1 || type == 2 || type == 4 || type == 7){
                        if(np == 3 || np == 4 || np == 7) continue;
                    }
                }


                if (visited[ny][nx] == 0) {
                    visited[ny][nx] = cnt + 1;
                    q.push({{nx, ny}, cnt + 1});
                }
            }



        }

        int ans = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if(visited[y][x] >= 1 && visited[y][x] <= l){
                    ans++;
                }
            }
        }


        cout << "#" << j << " " << ans << "\n";

    }


    return 0;
}