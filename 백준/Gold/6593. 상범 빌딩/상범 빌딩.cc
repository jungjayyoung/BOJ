#include <iostream>
#include <queue>
#include <string>
#define NMAX 98765432
using namespace std;


int l, r, c;


char map[31][31][31];
int visited[31][31][31];
int dx[] = {-1, 0, 1, 0,0,0};
int dy[] = {0, 1, 0, -1,0,0};
int dz[] = {0,0,0,0,1,-1};
int ans = NMAX;

void bfs(){

    queue<pair<pair<int,int>,pair<int,int>>> q;


  for (int z = 0; z < l; z++) {
        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++) {
                if (map[z][y][x] == 'S') {
                    visited[z][y][x] = 1;
                    q.push({{x, y},{z, 0}});
                    goto SKIP;
                }
            }
        }
    }
  SKIP:
    while (!q.empty()) {

        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int curz = q.front().second.first;
        int cnt = q.front().second.second;

        q.pop();

        if(map[curz][cury][curx] == 'E') {
            ans = cnt;
            break;
        }


        for (int i = 0; i < 6; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            int nz = curz + dz[i];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= c || ny >= r || nz >= l) {
                continue;
            }
            if(visited[nz][ny][nx]) continue;

            if ((map[nz][ny][nx] == '.' || map[nz][ny][nx] == 'E') && !visited[nz][ny][nx]) {
                visited[nz][ny][nx] = 1;
                q.push({{nx, ny},{nz, cnt + 1}});
            }


        }

    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while(1) {

        fill(&visited[0][0][0], &visited[31][0][0], 0);
        ans = NMAX;
        cin >> l >> r >> c;

        if (l == 0 && r == 0 && c == 0) {
            return 0;
        }

        for (int z = 0; z < l; z++) {
            for (int y = 0; y < r; y++) {
                string str;
                cin >> str;
                for (int x = 0; x < c; x++) {
                    map[z][y][x] = str[x];
                }
            }
        }

        bfs();


        if (ans != NMAX) {
            cout << "Escaped in " << ans << " minute(s).";
        }else{
            cout << "Trapped!";
        }

        cout << "\n";


    }



    return 0;
}