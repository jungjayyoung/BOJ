#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int visited[25];
int visited2[25];

char map[5][5];
int cnt;
int ans;
vector<int> v;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(){


    fill(visited2, visited2 + 25, 0);

    queue<int> q;

    q.push(v[0]);
    visited2[v[0]] = 1;

    cnt = 1;

    while (!q.empty()) {

        int cur = q.front();

        int cury = cur / 5;
        int curx = cur % 5;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            int next = ny * 5 + nx;

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) {
                continue;
            }

            if(visited[next] && !visited2[next]){
                visited2[next] = 1;
                cnt++;
                q.push(next);
            }

        }

    }

}

void comb(int idx,int start,int y_cnt,int s_cnt){


    // 임도연파가 4명 이상이면 return
    if(y_cnt >= 4) return;

    if (idx >= 7) {
        cnt = 1;
        bfs();
        if (cnt == 7) {
            ans++;
        }
        return;
    }





    for (int i = start; i < 25; i++) {

        visited[i] = 1;
        int y = i / 5;
        int x = i % 5;

        v.push_back(i);
        if (map[y][x] == 'Y') {
            comb(idx + 1, i + 1, y_cnt + 1, s_cnt);
        }else{
            comb(idx + 1, i + 1, y_cnt, s_cnt + 1);
        }
        v.pop_back();
        visited[i] = 0;

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    for (int y = 0; y < 5; y++) {

        string str;
        cin >> str;
        for (int x = 0; x < 5; x++) {
            map[y][x] = str[x];
        }
    }

    ans = 0;

    comb(0, 0, 0, 0);


    cout << ans;

    return 0;
}