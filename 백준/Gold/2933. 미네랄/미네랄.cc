#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;


char map[101][101];
int r, c, n;
bool mineral_crash = false;
int visited[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

vector<int> h;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> r >> c;


    for (int y = 0; y < r; y++) {

        string str;
        cin >> str;
        for (int x = 0; x < c; x++) {
            map[y][x] = str[x];
        }
    }
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        h.push_back(num);
    }



    for(int i = 0; i < h.size(); i++){

        int hh = h[i]; // 현재 부수는 높이
        mineral_crash = false;

        if (i % 2 == 0) { // 왼쪽에서 오른쪽으로 던짐

            for (int x = 0; x < c; x++) {
                if (map[r - hh][x] == 'x') {
                    mineral_crash = true;
                    map[r - hh][x] = '.';
                    break;
                }
            }

        } else if (i % 2 == 1) {// 오른쪽에서 왼쪽으로 던짐
            for (int x = c-1; x >= 0; x--) {
                if (map[r - hh][x] == 'x') {
                    mineral_crash = true;
                    map[r - hh][x] = '.';
                    break;
                }
            }
        }

        // 막대가 미네랄을 만났을때
        if (mineral_crash) {

            //1. 공중에 떠있는 미네랄 클러스터가 있는지 체크한다.
            //2. 땅에 있는 미네랄라인만 너비우선 탐색으로 방문 탐색한다.
            queue<pair<int,int>> mc;
            fill(&visited[0][0], &visited[101][0], 0);
            for (int x = 0; x < c; x++) {
                if (map[r - 1][x] == 'x') {
                    mc.push({x, r - 1});
                    visited[r-1][x] = 1;
                }
            }

            // 공중에 있지 않은 클러스터는 visited로 체크해준다.
            while (!mc.empty()) {
                int curx = mc.front().first;
                int cury = mc.front().second;

                mc.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = curx + dx[i];
                    int ny = cury + dy[i];

                    if(nx < 0 || ny < 0 || nx >= c || ny >= r) continue;

                    if (!visited[ny][nx] && map[ny][nx] == 'x') {
                        visited[ny][nx] = 1;
                        mc.push({nx, ny});
                    }
                }

            }

            // 모든 x,y 를 탐색하면서 공중에 떠 있는 클러스터가 있다면
            // 공중에 떠 있지 않을 때까지 해당 클러스터를 바닥으로 내린다.
            // 반드시 밑에서부터 큐를 채워준다!!
            for (int y = r - 1; y >= 0; y--) {
                for (int x = 0; x < c; x++) {
                    if (!visited[y][x] && map[y][x] == 'x') {
                        mc.push({x, y});
                    }
                }
            }

            int cluster_size = mc.size();

            int cnt;
            while (!mc.empty()) {


                cnt = 0;
                bool check = false;

                while (cnt < cluster_size) {

                    int curx = mc.front().first;
                    int cury = mc.front().second;

                    mc.pop();
                    // 현재 위치를 빈칸으로 만들고 다음 칸을 x로 만든다.
                    // 처음에 밑에서부터 큐를 집어넣은 이유가 여기서 중복이
                    // 발생할 수 있기 때문이다.
                    int nx = curx;
                    int ny = cury + 1;
                    map[cury][curx] = '.';
                    map[ny][nx] = 'x';

                    // 다음에 내릴 칸의 위치를 큐에 집어넣는다.
                    mc.push({nx, ny});
                    // 밑에가 바닥이나 다른 클러스트인지 체크해준다.
                    if (ny + 1 == r || visited[ny + 1][nx]) {
                        check = true;
                    }
                    cnt++;
                }

                // 다른 클러스터를 만나거나 바닥을 만나면 빠져나온다.
                if (check) {
                    break;
                }

            }

            while (!mc.empty()) mc.pop();
        }



    }

    for (int y = 0; y < r; y++) {

        for (int x = 0; x < c; x++) {
            cout << map[y][x];
        }
        cout << "\n";
    }



    return 0;
}