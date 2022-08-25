#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;


int k,w,h;

int board[201][201];
bool visited[201][201][32]; // x,y 지점에 능력을 n 번 사용해서 도착했다 라는 의미
queue<pair<pair<int,int>,pair<int,int>>> q;
int dx[] = {-1,0,1,0 };
int dy[] = {0,1,0,-1};
int hdx[] = {-2,-2,-1,-1,1,1,2,2};
int hdy[] = {1,-1,2,-2,2,-2,1,-1};
int ans = 98765432;
bool check = false;
void bfs(){

    q.push({{0,0},{0,0}});

    // 말 점프로 갔는지 그냥 갔는지를 체크해야 한다

    visited[0][0][0] = true; // 그냥 이동

    while(!q.empty()){

        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int jump_cnt = q.front().second.first; // 점프 횟수
        int cnt = q.front().second.second; // 이동 횟수

        q.pop();

        if(curx == w - 1 && cury == h - 1){

            ans = min(ans,cnt);
            check = true;
        }



        for(int i = 0; i < 4; i++){
            int nextx = curx + dx[i];
            int nexty = cury + dy[i];

            if(nextx < 0 || nexty < 0 || nextx >= w || nexty >= h || board[nexty][nextx] == 1) continue;

            if(board[nexty][nextx] == 0 && !visited[nexty][nextx][jump_cnt]){

                q.push({{nextx,nexty},{jump_cnt, cnt + 1}});
                visited[nexty][nextx][jump_cnt] = true;

            }
        }
        if(jump_cnt < k){

            for (int i = 0; i < 8; i++) {
                int nextx = curx + hdx[i];
                int nexty = cury + hdy[i];

                if(nextx < 0 || nexty < 0 || nextx >= w || nexty >= h || board[nexty][nextx] == 1) continue;

                if(board[nexty][nextx] == 0 && !visited[nexty][nextx][jump_cnt + 1]){
                    q.push({{nextx,nexty},{jump_cnt + 1, cnt + 1}});
                    visited[nexty][nextx][jump_cnt + 1] = true;
                }

            }

        }


    }





}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> k >> w >> h;


    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> board[y][x];
        }
    }


    
    bfs();


    if(check){
        cout << ans;
    }else{
        cout << -1;
    }


    return 0;
}