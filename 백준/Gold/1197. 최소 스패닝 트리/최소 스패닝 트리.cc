#include <iostream>
#include <algorithm>


using namespace std;

int parent[10001];
int tree_level[10001];
int ans = 0;
pair<pair<int, int>, int> edge[100001];


bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second < b.second;
}

int find_parent(int u){

    if(parent[u] == u){

        return u;
    }

    return parent[u] = find_parent(parent[u]);

}

void join_node(int u, int v,int cost){


    u = find_parent(u);
    v = find_parent(v);

    if (u == v) {
        return;
    }

    if (tree_level[u] < tree_level[v]) {
        parent[u] = v;
        tree_level[u] += tree_level[v];
    }else{
        parent[v] = u;
        tree_level[v] += tree_level[u];
    }

    ans += cost;
    return;

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int v, e;
    cin >> v >> e;
    fill(tree_level, tree_level + 10001, 1);
    for (int i = 1; i <= 10000; i++) {
        parent[i] = i;
    }


    for (int i = 0; i < e; i++) {
        cin >> edge[i].first.first >> edge[i].first.second >> edge[i].second;
    }

    sort(edge, edge + e, cmp);

    for (int i = 0; i < e; i++) {
        int a, b, c;

        a = edge[i].first.first;
        b = edge[i].first.second;
        c = edge[i].second;

        join_node(a, b,c);

    }


    cout << ans;

    return 0;
}