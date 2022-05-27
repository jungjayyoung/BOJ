#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n,m;
int cnt = 0;

vector<int> v[10001];
vector<int> ans;
int maxx = -1;
int visited[100001];

void dfs(int node){

    visited[node] = 1;
    cnt++;

    for (int i = 0; i < v[node].size(); i++) {

        if (!visited[v[node][i]]) {
            dfs(v[node][i]);
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
        v[b].push_back(a);
    }


    for (int i = 1; i <= n; i++) {

        cnt = 0;

        fill(visited, visited + n + 1, 0);
        dfs(i);


        if (maxx < cnt) {
            ans.clear();
            maxx = cnt;
            ans.push_back(i);

        } else if (maxx == cnt) {
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}