#include <iostream>



using namespace std;

int parent[500001];
int tree_level[500001];
bool check = false;
int find_parent(int u){

    if (parent[u] == u) {

        return u;
    }

    return parent[u] = find_parent(parent[u]);

}

void join_node(int u,int v){

    u = find_parent(u);
    v = find_parent(v);

    if (u == v) {

        check = true;
        return;
    }

    if (tree_level[u] <= tree_level[v]) {
        parent[u] = v;
        tree_level[u] += tree_level[v];
    }else{
        parent[v] = u;
        tree_level[v] += tree_level[u];
    }


    return;

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    fill(tree_level, tree_level + n + 1, 1);

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        join_node(a, b);
        if(check) {
            cout << i;
            return 0;
        }
    }

    cout << 0;


    return 0;
}