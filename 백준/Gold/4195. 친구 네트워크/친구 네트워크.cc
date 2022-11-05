#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int parent[200001];
int tree_level[200001];
map<string,int> m;

int find_parent(int u){

    if(parent[u] == u){
        return u;
    }
    return parent[u] = find_parent(parent[u]);
}

void join_node(int u, int v){

    u = find_parent(u);
    v = find_parent(v);

    if(u == v) {
        cout << max(tree_level[u],tree_level[v]) << "\n";
        return;
    }

    if (tree_level[u] <= tree_level[v]) {
        parent[u] = v;
        tree_level[v] += tree_level[u];
        cout << tree_level[v] << "\n";
    }else{
        parent[v] = u;
        tree_level[u] += tree_level[v];
        cout << tree_level[u] << "\n";
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {


        m.clear();
        fill(tree_level, tree_level + 200001, 1);
        for (int j = 0; j <= 200000; j++) {
            parent[j] = j;
        }
        int r_size;
        cin >> r_size;
        int cnt = 0;
        for (int j = 0; j < r_size; j++) {
            string a, b;
            int aa, bb;
            cin >> a >> b;
            if (m.find(a) == m.end()) {
                m.insert({a, cnt});
                aa = cnt;
                cnt++;
            }else{
                aa = m[a];
            }

            if(m.find(b) == m.end()){
                m.insert({b, cnt});
                bb = cnt;
                cnt++;
            }else{
                bb = m[b];
            }

            join_node(aa, bb);
        }

    }

    return 0;
}