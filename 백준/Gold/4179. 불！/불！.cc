#include <iostream>
#include <deque>

using namespace std;

int r, c;
char board[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool visited[1001][1001];
bool check;
deque<pair<pair<int,int>,pair<int,int>>> q;
int ans = 0;

void bfs(){


    while (!q.empty()) {

        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int is_fire = q.front().second.second;

        q.pop_front();

        if (is_fire == 0 && (x == 0 || x == c - 1 || y == 0 || y == r - 1)) {

            ans = cnt;
            check =true;
            break;
        }

        for (int i = 0; i < 4; i++) {

            int nextx = x + dx[i];
            int nexty = y + dy[i];

            if (nextx < 0 || nexty < 0 || nextx >= c || nexty >= r) {
                continue;
            }

            if (!visited[nexty][nextx] && board[nexty][nextx] == '.' && is_fire == 1) {
                visited[nexty][nextx] = true;
                q.push_back({{nextx,   nexty},{cnt + 1, is_fire}});
            } else if (!visited[nexty][nextx] && board[nexty][nextx] == '.' && is_fire == 0) {
                visited[nexty][nextx] = true;
                q.push_back({{nextx,   nexty},{cnt + 1, is_fire}});
            }



        }


    }



}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;


    for (int y = 0; y < r; y++) {

        for (int x = 0; x < c; x++) {
            cin >> board[y][x];
            if (board[y][x] == 'J') {
                q.push_back({{x, y},{0,0}});
            } else if(board[y][x] == 'F'){
                q.push_front({{x,y},{0,1}});
            }
        }
    }


    bfs();

    if (check) {
        cout << ans + 1;
    }else{
        cout << "IMPOSSIBLE";
    }


    return 0;
}