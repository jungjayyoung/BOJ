#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int n, m;

vector<int> v[50001];
int parent[50001];
int visited[50001];


void dfs(int cur,int pre){

    visited[cur] = 1;
    parent[cur] = pre;

    for (int i = 0; i < v[cur].size(); i++) {
        int next = v[cur][i];

        if (!visited[next]) {
            dfs(next, cur);
        }

    }

}

int find_parent(int u){

    if (visited[u]) {

        return u;
    }

    visited[u] = 1;

    if (parent[u] == u) {
        return u;
    }

    return find_parent(parent[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }


    dfs(1, 1);
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        fill(visited, visited + n + 1, 0);


        find_parent(a);
        cout << find_parent(b) << "\n";

    }




    return 0;
}