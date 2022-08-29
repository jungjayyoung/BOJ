#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;


int board[126][126];
bool visited[126][126];
int dist[126][126];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


struct cmp{

    bool operator()(pair<pair<int,int>,int> a , pair<pair<int,int>,int> b){
        return a.second > b.second;
    }

};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;



    while (true) {

        int n;

        cin >> n;

        if (n == 0) {
            break;
        }

        for(int y = 0; y <n; y++){

            for(int x = 0; x < n; x++){
                cin >> board[y][x];
                //board[y][x] = -board[y][x];
            }
        }

        fill(&visited[0][0], &visited[n + 1][0], false);
        fill(&dist[0][0], &dist[n+1][0],INT_MAX);


        dist[0][0] = board[0][0];

        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>, cmp> q;

        q.push({{0, 0}, board[0][0]});

        while (!q.empty()) {

            int x = q.top().first.first;
            int y = q.top().first.second;
            int money = q.top().second;

            q.pop();

            if(visited[y][x]) continue;

            visited[y][x] = true;


            if (x == n - 1 && y == n - 1) {

                break;
            }

            for (int i = 0; i < 4; i++) {
                int nextx = x + dx[i];
                int nexty = y + dy[i];

                if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n) {
                    continue;
                }

                if(!visited[nexty][nextx]
                && dist[nexty][nextx] > money + board[nexty][nextx]){

                    dist[nexty][nextx] = money + board[nexty][nextx];
                    q.push({{nextx, nexty}, dist[nexty][nextx]});

                }


            }


        }


        cout << "Problem " << t << ": " << dist[n - 1][n - 1] << "\n";

        t++;
    }






    return 0;
}
