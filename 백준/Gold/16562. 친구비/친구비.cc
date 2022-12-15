#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[10001];
int n, m, k;

int cost[10001];
int parent[10001];


int find_parent(int u){

    if (parent[u] == u) {
        return u;
    }

    return parent[u] = find_parent(parent[u]);
}

void join_node(int u, int v) {

    u = find_parent(u);
    v = find_parent(v);

    if (u == v) {
        return;
    }

    // 비용이 작은 것이 부모가 된다.
    if (cost[u] <= cost[v]) {
        parent[v] = u;
    }else{
        parent[u] = v;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        parent[i] = i;
    }
    parent[0] = 0;

    for (int i = 0; i < m; i++) {
        int vv, w;
        cin >> vv >> w;
        if(vv == w) continue;

        join_node(vv, w);

    }

    int sum = 0;

    for (int i = 1; i <= n; i++) {
        int p = find_parent(i);

        if (p != 0) {
            sum += cost[p];
            join_node(0, p);
        }
    }

    if (sum <= k) {
        cout << sum;
    }else
        cout << "Oh no";


    return 0;
}