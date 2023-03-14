#include <iostream>
#include <vector>

using namespace std;


int n;
vector<int> v[1001];
int visited[1001];
int loopy[1001];
bool check = false;

void dfs(int idx){

    visited[idx] = 1;

    if(v[idx].empty()) return;

    int next_idx = v[idx][0];
    if (visited[next_idx] == 1 || loopy[next_idx] == 1) {
        check = true;
        loopy[idx] = 1;
        return;
    } else {
        dfs(next_idx);
    }

    if (check) {
        loopy[idx] = 1;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;


    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if(a == 0) continue;
        v[i].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {

        fill(visited, visited + n + 1, 0);
        check = false;
        if(v[i].empty()) continue;
        if (loopy[i] == 0) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (loopy[i] == 0) {
            ans++;
        }
    }

    cout << ans;



    return 0;
}