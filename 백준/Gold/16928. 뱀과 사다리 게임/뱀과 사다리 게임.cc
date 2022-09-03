#include <iostream>
#include <queue>


using namespace std;

int n,m;

int snake[101];
int ladder[101];
int visited[101];
queue<pair<int,int>> q; //현재칸, 이동횟수
int ans = 987654321;

void bfs(){



    while(!q.empty()){

        int cur = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (cur == 100) {
            ans = cnt;
            return;
        }
        for (int i = 1; i <= 6; i++) {

            int next = cur + i;
            if(next > 100) continue;

            if(visited[next]) continue;
            
            if (ladder[next] != 0) {
                q.push({ladder[next],cnt + 1});
                //visited[ladder[next]] = 1;
                visited[next] = 1;
            } else if (snake[next] != 0) {
                q.push({snake[next], cnt + 1});
                //visited[snake[next]] = 1;
                visited[next] = 1;
            }else{
                q.push({next, cnt + 1});
                visited[next] = 1;
            }

        }

    }


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;


    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        ladder[a] = b;

    }

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        snake[a] = b;
    }

    q.push({1,0});


    bfs();


    cout << ans;



    return 0;
}