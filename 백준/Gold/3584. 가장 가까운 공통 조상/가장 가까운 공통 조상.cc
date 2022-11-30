#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int t;
int n;
int visited[10001];
int parent[10001];

int find_parent(int u){

    if (visited[u]) {


        return u;
    }

    visited[u] = 1;

    if (parent[u] == u) {

        return u;
    }


    return find_parent(parent[u]);

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> t;


    for (int i = 1; i <= t; i++) {

        cin >> n;

        fill(visited, visited + n + 1, 0);

        for (int j = 1; j <= n; j++) {
            parent[j] = j;
        }

        for (int j = 0; j < n - 1; j++) {
            int a, b;
            cin >> a >> b;

            parent[b] = a;
        }

        int node1, node2;

        cin >> node1 >> node2;

        find_parent(node1);


        cout << find_parent(node2) << "\n";


    }



    return 0;
}