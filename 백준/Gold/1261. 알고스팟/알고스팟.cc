#include <iostream>
#include <queue>
#include <limits.h>
#include <string>

using namespace std;

int n,m;

int board[101][101];
int dist[101][101];
bool visited[101][101];
int dx[] = {-1,0,1,0};
int dy[] = {0, 1, 0, -1};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;

    for (int y = 1; y <= n; y++) {
        string s;
        cin >> s;
        for (int x = 1; x <= m; x++) {
            board[y][x] = s[x - 1] - '0';
        }
    }



    fill(&dist[0][0], &dist[101][0], INT_MAX);
    dist[1][1] = 0;

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

    pq.push({dist[1][1], {1, 1}});



    while(!pq.empty()){

        int weight = pq.top().first;
        int curx = pq.top().second.first;
        int cury = pq.top().second.second;

        pq.pop();

        if (curx == m && cury == n) {

            break;
        }
        for (int i = 0; i < 4; i++) {
            int nextx = curx + dx[i];
            int nexty = cury + dy[i];
            int next_weight = board[nexty][nextx];

            if(nextx < 1 || nexty < 1 || nextx > m || nexty > n) continue;


            if (dist[nexty][nextx] > weight + next_weight) {
                dist[nexty][nextx] = weight + next_weight;
                pq.push({dist[nexty][nextx], {nextx, nexty}});
            }

        }
    }

    cout << dist[n][m];

    return 0;
}