#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;

vector<int> v[101];
queue<pair<int,int>> q; // 현재 노드, 케빈 베이컨 카운트
int visited[101];
int ans_cnt = 87654321;
int ans_num = 87654321;

void bfs(int num){


    q.push({num, 0});
    visited[num] = 1;

    int sum = 0;

    while(!q.empty()){

        int cur_node = q.front().first;
        int cur_cnt = q.front().second;

        q.pop();

        sum += cur_cnt;

        for (int i = 0; i < v[cur_node].size(); i++) {

            if (!visited[v[cur_node][i]]) {
                visited[v[cur_node][i]] = 1;
                q.push({v[cur_node][i], cur_cnt + 1});
            }

        }

    }


    if (ans_cnt > sum) {
        ans_cnt = sum;

        ans_num = num;

    }


}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);

    }

    for (int i = 1; i <= n; i++) {

        fill(visited, visited + n + 1, 0);

        bfs(i);

    }

    cout << ans_num;

    return 0;
}