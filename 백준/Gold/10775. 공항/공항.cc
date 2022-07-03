#include <iostream>
#include <vector>

using namespace std;


int parent[100001];
int tree_level[100001];
int visited[100001];
vector<int> v;

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
        return;
    }

    if (tree_level[u] < tree_level[v]) {
        parent[u] = v;
        tree_level[u] += tree_level[v];
    }else{
        parent[v] = u;
        tree_level[v] = u;
    }


    return;



}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int g, p;

    cin >> g >> p;

    //게이트가 사용되었다면
    parent[1] = 1;
    for (int i = 2; i <= g; i++) {
        parent[i] = i - 1;
    }

    fill(tree_level, tree_level + g + 1, 1);

    int ans = 0;


    for (int i = 0; i < p; i++) {
        int g;
        cin >> g;
        v.push_back(g);
    }
    for (int i = 0; i < v.size(); i++) {
        int g, a;
        bool check = false;
        a = g = v[i];

        while (g != 1) {
            if (!visited[g]) {
                visited[g] = 1;
                check = true;
                ans++;
                parent[a] = g - 1;

                break;
            }else{
                g = parent[g];
            }
        }

        if (g == 1) {
            if (!visited[g]) {
                visited[g] = 1;
                check = true;
                ans++;
            }
        }

        if (!check) {
            break;
        }
    }

    cout << ans;

    return 0;
}