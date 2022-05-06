#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int board[101][101];
int visited[101][101];
vector<int> v[101];


void bfs(int num){

    queue<int> q;

    for (int i = 0; i < v[num].size(); i++) {
        q.push(v[num][i]);
    }


    while (!q.empty()) {

        int cur_node = q.front();
        q.pop();

        if (!visited[num][cur_node]) {
            visited[num][cur_node] = 1;
        }

        for (int i = 0; i < v[cur_node].size(); i++) {

            if (visited[num][v[cur_node][i]]) continue;
            q.push(v[cur_node][i]);
        }
    }



}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int y = 1; y <= n; y++) {

        for (int x = 1; x <= n; x++) {
            cin >> board[y][x];

            if (board[y][x] == 1) {
                v[y].push_back(x);
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        bfs(i);
    }


    for (int y = 1; y <= n; y++) {

        for (int x = 1; x <= n; x++) {
            cout << visited[y][x] << " ";
        }
        cout << "\n";
    }
    return 0;
}