#include <iostream>
#include <vector>

using namespace std;

int tree_level[201];
int parent[201];

vector<int> v;


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

    if (tree_level[u] < tree_level[v]) {
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


    int n, k;
    fill(tree_level, tree_level + 200, 1);

    for (int i = 1; i <= 200; i++) {
        parent[i] = i;
    }


    cin >> n >> k;


    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {
            int num;
            cin >> num;

            if (num == 1) {
                if (find_parent(i) != find_parent(j)) {
                    join_node(i, j);
                }

            }
        }

    }

    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;

        v.push_back(t);
    }

    int parent_city = find_parent(v[0]);
    bool check = false;

    for (int i = 1; i < v.size(); i++) {
        if (parent_city != find_parent(v[i])) {
            check = true;
            break;
        }
    }


    if (check) {
        cout << "NO";
    }else
        cout << "YES";




    return 0;
}