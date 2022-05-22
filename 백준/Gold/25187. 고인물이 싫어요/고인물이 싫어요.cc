#include <iostream>

using namespace std;


int n,m,k;

int visited[100001];
int tank_state[100001];
int parent[100001];
int tree_height[100001];

int find_parent(int u){
    if (parent[u] == u) {
        return u;
    }

    return parent[u] = find_parent(parent[u]);
}

void join_node(int u, int v){
    u = find_parent(u);
    v = find_parent(v);

    if(u == v) return;

    if(tree_height[u] > tree_height[v]) swap(u, v);
    parent[u] = v;
    tree_height[v] += tree_height[u];

}


int sum[100001]; // 청정수 합


// 유니온 파인드로 푸는 문제

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    for(int i = 1; i<=100000;i++){
        parent[i] = i;
    }

    for(int i = 1; i<=100000;i++){
        tree_height[i] = 1;
    }
    cin >> n >> m >> k;


    for (int i = 1; i <= n; i++) {
        cin >> tank_state[i];
    }

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        join_node(a, b);

    }

    for (int i = 1; i <= n; i++) {
        if (tank_state[i]) {
            sum[find_parent(i)] += 1;
        }
    }

    for (int i = 0; i < k; i++) {
        int node;
        cin >> node;

        int parent_node = find_parent(node);

        if ((sum[parent_node] * 2) > tree_height[parent_node]) {
            cout << 1 << "\n";
        }else
            cout << 0 << "\n";

    }


    return 0;
}