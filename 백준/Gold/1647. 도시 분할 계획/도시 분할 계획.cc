#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int n,m;


int parent[100001];
int tree_level[100001];
vector<pair<int,pair<int,int>>> v;


int find_parent(int u){

    if (parent[u] == u) {
        return u;
    }

    return parent[u] = find_parent(parent[u]);
}

void join_node(int u, int v){

    u = find_parent(u);
    v = find_parent(v);

    if(u == v){
        return;
    }

    if (tree_level[u] <= tree_level[v]) {
        parent[u] = parent[v];
        tree_level[u] += tree_level[v];
    }else{
        parent[v] = parent[u];
        tree_level[v] += tree_level[u];
    }

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    fill(tree_level, tree_level + 100001, 1);

    for (int i = 0; i < n+1; i++) {
        parent[i] = i;
    }


    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int last_weight = 0;
    for (int i = 0; i < m; i++) {
        int weight = v[i].first;
        int a = v[i].second.first;
        int b = v[i].second.second;

        if (find_parent(parent[a]) != find_parent(parent[b])) {
            join_node(a, b);
            ans += weight;
            last_weight = weight;
        }

    }


    cout << ans - last_weight;


    return 0;
}