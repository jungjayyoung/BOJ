#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int visited[10];
vector<pair<int,int>> egg;
vector<int> order;
int ans = 0;

void dfs(int idx){

    if (idx >= n) {
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (egg[i].first <= 0) {
                cnt++;
            }
        }

        ans = max(ans, cnt);

        return;
    }

    bool check = false;

    for (int i = 0; i < n; i++) {
        if (i == idx) continue;
        if (egg[idx].first > 0 && egg[i].first > 0) {
            egg[idx].first -= egg[i].second;
            egg[i].first -= egg[idx].second;
            check = true;
            dfs(idx + 1);
            egg[idx].first += egg[i].second;
            egg[i].first += egg[idx].second;
        }

    }

    if(!check) dfs(idx + 1);


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        egg.push_back({a, b});
    }

    dfs(0);

    cout << ans;


    return 0;
}