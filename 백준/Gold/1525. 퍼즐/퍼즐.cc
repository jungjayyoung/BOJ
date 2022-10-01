#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
using namespace std;


int board[3][3];
int visited[3][3];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
set<string> ss;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    queue<pair<string,int>> q; // string, cnt
    string tmp;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cin >> board[y][x];
            tmp += to_string(board[y][x]);
        }
    }


    q.push({tmp,0});
    ss.insert(tmp);


    while (!q.empty()) {

        //현재 0의 x,y 좌표
        string cur = q.front().first;
        int cnt = q.front().second;
        int pos0 = cur.find('0');
        int curx = pos0 % 3;
        int cury = pos0 / 3;

        q.pop();

        if (cur == "123456780") {
            cout << cnt;
            return 0;
        }




        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if(nx < 0  || ny < 0 || nx >= 3 || ny >= 3) continue;

            int change_pos = ny * 3 + nx;

            char tmpp;
            tmpp = cur[change_pos];
            cur[change_pos] = cur[pos0];
            cur[pos0] = tmpp;


            if (cur == "123456780") {
                cout << cnt + 1;
                return 0;
            }

            //bool check2 = false;
            auto check = ss.find(cur);


            if (check == ss.end()) {
                //cout << cur << " " << cnt << "\n";
                q.push({cur, cnt + 1});
                ss.insert(cur);
            }



            tmpp = cur[change_pos];
            cur[change_pos] = cur[pos0];
            cur[pos0] = tmpp;

        }




    }


    cout << -1;

    return 0;
}