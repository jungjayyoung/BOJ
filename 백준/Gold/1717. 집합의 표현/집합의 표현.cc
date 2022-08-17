#include <iostream>



using namespace std;


int tree_level[1000001];
int parent[1000001];



int find_parent(int u){

    if(parent[u] == u){

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

    if(tree_level[u] <= tree_level[v]){
        tree_level[u] += tree_level[v];
        parent[u] = v;
    }else{
        tree_level[v] += tree_level[u];
        parent[v] = u;
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n, m;

    cin >> n >> m;

    fill(tree_level, tree_level + n + 1, 1);

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i <m; i++){
        int a,b,c;
        cin >> a >> b >> c;

        if (a == 1) {
            if(find_parent(b) == find_parent(c)){
                cout << "YES" << "\n";
            }else{
                cout << "NO" << "\n";
            }

        } else if (a == 0) {
            join_node(b, c);
        }

    }

    return 0;
}