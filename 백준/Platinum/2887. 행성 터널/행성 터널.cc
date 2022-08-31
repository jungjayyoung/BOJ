#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int n;

vector<pair<int,int>> x;
vector<pair<int,int>> y;
vector<pair<int,int>> z;
vector<pair<int,pair<int,int>>> vertex;

int parent[100001];
int tree_level[100001];
int find_parent(int u){

    if (parent[u] == u) {
        return u;
    }
    return parent[u] = find_parent(parent[u]);
}

void join_node(int u, int v){

    u = find_parent(u);
    v = find_parent(v);

    if (u == v) {
        return;
    }

    if (tree_level[u] <= tree_level[v]) {
        tree_level[u] += tree_level[v];
        parent[u] = v;
    }else{
        tree_level[v] += tree_level[u];
        parent[v] = u;
    }
}

bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){

    return a.first < b.first;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    fill(tree_level, tree_level + 100001, 1);



    cin >> n;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int a,b,c;
        cin >> a >> b >> c;

        x.push_back({a, i});
        y.push_back({b, i});
        z.push_back({c, i});

    }

    sort(x.begin(),x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());


    for (int i = 1; i < n; i++) {
        vertex.push_back({x[i].first - x[i - 1].first, {x[i].second, x[i - 1].second}});
        vertex.push_back({y[i].first - y[i - 1].first, {y[i].second, y[i - 1].second}});
        vertex.push_back({z[i].first - z[i - 1].first, {z[i].second, z[i - 1].second}});
    }


    sort(vertex.begin(), vertex.end(), cmp);

    int ans = 0;
    for (int i = 0; i < vertex.size(); i++) {

        int a = vertex[i].second.first;
        int b = vertex[i].second.second;


        if(find_parent(parent[a]) != find_parent(parent[b])){
            join_node(a, b);
            ans += vertex[i].first;
        }

    }

    cout << ans;

    return 0;
}