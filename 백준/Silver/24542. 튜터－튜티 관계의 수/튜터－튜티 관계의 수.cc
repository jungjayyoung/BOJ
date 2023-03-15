#include <iostream>
#include <vector>
#define NMAX 1000000007
using namespace std;

typedef long long ll;



vector<int> v[200001];
int visited[200001];
vector<int> tree_node_cnt;

int n, m;

int dfs(int idx){

    visited[idx] = 1;

    int cnt = 1;

    for (int i = 0; i < v[idx].size(); i++) {
        int next = v[idx][i];

        if(!visited[next]){
            cnt += dfs(next);
        }
    }

    return cnt;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {

        int cntt = 0;

        if (visited[i] == 0) {
            cntt += dfs(i);
            tree_node_cnt.push_back(cntt);
        }

    }

    ll ans = 1;

    for (int i = 0; i < tree_node_cnt.size(); i++) {
        ans = (ans * tree_node_cnt[i]) % NMAX;
    }

    cout << ans;

    return 0;
}