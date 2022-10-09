#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

char board[12][6];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool is_end = false;
bool visited[12][6];
int cnt;

vector<pair<int,int>> tmp,v;
queue<pair<int,int>> q;

void bfs(char a){

    while (!q.empty()) {

        int curx = q.front().first;
        int cury = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if(nx <0 || ny < 0 || nx >= 6 || ny >= 12) continue;
            if(board[ny][nx] != a) continue;
            if(visited[ny][nx]) continue;

            cnt++;
            visited[ny][nx] = true;
            tmp.push_back({nx, ny});
            q.push({nx, ny});

        }

    }

}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int y = 0; y < 12; y++){
        string a;
        cin >> a;
        for (int x = 0; x < 6; x++) {
            board[y][x] = a[x];
        }
    }

    int ans = 0;
    while (true) {

        is_end = false;
        fill(&visited[0][0], &visited[12][0], 0);
        v.clear();

        for (int y = 0; y < 12; y++) {
            for (int x = 0; x < 6; x++) {

                if(board[y][x] != '.' && !visited[y][x]){
                    cnt = 1;
                    visited[y][x] = true;
                    q.push({x, y});
                    tmp.push_back({x, y});
                    bfs(board[y][x]);

                    if (cnt >= 4) {
                        is_end = true;
                        for (int i = 0; i < tmp.size(); i++) {
                            v.push_back(tmp[i]);
                        }
                    }
                }
                tmp.clear();

            }
        }


        for (int i = 0; i < v.size(); i++) {
            int x = v[i].first;
            int y = v[i].second;

            board[y][x] = '.';
        }


        for (int i = 10; i >= 0; i--) {

            for (int j = 0; j < 6; j++) {

                if(board[i][j] == '.') continue;
                int tmpp = i;

                while (1) {
                    if(tmpp == 11 || board[tmpp+1][j] != '.') break;

                    board[tmpp + 1][j] = board[tmpp][j];
                    board[tmpp][j] = '.';
                    tmpp++;
                }
            }
        }

        // 터진게 없으면 나간다.
        if (!is_end){
            break;
        }else{
            ans++;
        }

    }


    cout << ans;



    return 0;
}