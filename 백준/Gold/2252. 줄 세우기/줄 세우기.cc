#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int n, m;

vector<int> v[32001];
int inDegree[32001];
queue<int> q;


void solve(){

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }

    }

    while (!q.empty()) {

        int cur_node = q.front();


        q.pop();

        cout << cur_node << " ";


        for (int i = 0; i < v[cur_node].size(); i++) {

            int next_node = v[cur_node][i];

            if (inDegree[next_node] - 1 == 0) {
                q.push(next_node);
            }

            inDegree[next_node]--;

        }


    }



}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;


    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        v[a].push_back(b);
        inDegree[b]++;

    }

    solve();



    return 0;
}