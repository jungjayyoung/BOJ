#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


vector<pair<int, int>> v[1001]; // 다음 노드, 비용

int visited[1001];
int cache[1001][1001];
int n, m;
bool check = false;

void dfs(int cur, int cur_cost, int st, int goal){



    if (cache[st][cur] == -1) {
        cache[st][cur] = cur_cost;
        cache[cur][st] = cur_cost;

        if (cur == goal) {
            check = true;
            return;
        }
    }

    for (int i = 0; i < v[cur].size(); i++) {

        int next = v[cur][i].first;
        int next_cost = v[cur][i].second;

        if (!visited[next]) {
            visited[next] = 1;
            dfs(next, cur_cost + next_cost, st, goal);
        }

        if (check) {
            return;
        }

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;

    fill(&cache[0][0], &cache[1001][0], -1);

    for (int i = 1; i <= 1000; i++) {
        cache[i][i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {

        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b, c});
        v[b].push_back({a, c});


    }


    while (m--) {
        int a, b;

        fill(visited, visited + n + 1, 0);

        cin >> a >> b;

        check = false;

        if (cache[a][b] == -1) {
            visited[a] = 1;
            dfs(a, 0, a, b);
            cout << cache[a][b] << "\n";
        }else{
            cout << cache[a][b] << "\n";
        }

    }

    return 0;
}