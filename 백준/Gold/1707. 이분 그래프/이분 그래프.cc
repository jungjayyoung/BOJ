#include <iostream>
#include <vector>


using namespace std;


vector<int> vv[20001];
int node_state[20001];
bool check = false;

void dfs(int cur){

    if (check) {
        return;
    }


    for (int i = 0; i < vv[cur].size(); i++) {

        int next = vv[cur][i];

        if (!node_state[next]) {
            if (node_state[cur] == 1) {
                node_state[next] = 2;
            } else if (node_state[cur] == 2) {
                node_state[next] = 1;
            }
            dfs(next);
        }else{
            if (node_state[cur] == node_state[next]) {
                check = true;
            }
        }

        if (check) {
            return;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    while (k--) {
        int v, e;
        check = false;
        fill(node_state, node_state + 20000, 0);
        cin >> v >> e;

        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            vv[a].push_back(b);
            vv[b].push_back(a);
        }

        for (int i = 1; i <= v; i++) {
            if (!node_state[i]) {
                node_state[i] = 1;
                dfs(i);
            }

        }

        if (check) {
            cout << "NO" << "\n";
        }else
            cout << "YES" << "\n";



        for (int i = 1; i <= v; i++) {
            vv[i].clear();
        }

    }
}