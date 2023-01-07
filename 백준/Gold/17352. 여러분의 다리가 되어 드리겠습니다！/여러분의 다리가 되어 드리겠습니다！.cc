#include <iostream>

using namespace std;


int n;

int parent[300001];

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

    if (u <= v) {
        parent[u] = v;
    }else
        parent[v] = u;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n - 2; i++) {
        int a, b;
        cin >> a >> b;
        join_node(a, b);
    }

    int a1 = find_parent(1);

    for (int i = 2; i <= n; i++) {

        if (a1 != find_parent(parent[i])) {
            cout << 1 << " " << parent[i];
            return 0;
        }

    }

    return 0;
}