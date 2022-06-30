#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<pair<int, int>, int> a,pair<pair<int, int>, int> b){

    return a.second < b.second;
}

vector<pair<pair<int, int>, int>> v;

int tree_level[1001];
int parent[1001];
int ans = 0;

int find_parent(int u){

    if (parent[u] == u) {
        return u;
    }

    return parent[u] = find_parent(parent[u]);
}

void join_node(int u, int v, int cost){

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
        tree_level[v] += u;
    }
    ans += cost;
    return;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;

    cin >> n >> k;


    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        v.push_back({{a, b}, c});
    }

    fill(tree_level, tree_level + 1000, 1);
    for (int i = 1; i <= 1000; i++) {
        parent[i] = i;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < k; i++) {

        int a, b, c;
        a = v[i].first.first;
        b = v[i].first.second;
        c = v[i].second;

        join_node(a, b, c);

    }

    cout << ans;
    return 0;
}