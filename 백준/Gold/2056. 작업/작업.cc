#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[10001];
int time_cnt[10001];
int cache[10001];
int inDegree[10001];

queue<int> q;
int ans = 0;
int n;

void solve(){

    for(int i=1;i<=n;i++){


        if (inDegree[i] == 0) {
            q.push(i);
            cache[i] = time_cnt[i];
        }
    }



    while(!q.empty()){

        int cur_node = q.front(); // 현재 노드
        q.pop();

        for (int i = 0; i < v[cur_node].size(); i++) {


            int next_node = v[cur_node][i];

            if (inDegree[next_node] - 1 == 0) {

                q.push(next_node);
            }
            inDegree[next_node]--;

            cache[next_node] = max(cache[next_node], cache[cur_node] + time_cnt[next_node]);

        }

    }


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        time_cnt[i] = a;
        int cnt;
        cin >> cnt;


        for (int j = 0; j < cnt; j++) {
            int b;
            cin >> b;
            inDegree[i]++;
            v[b].push_back(i);
        }

    }


    solve();


    for (int i = 1; i <= n; i++) {

        ans = max(ans, cache[i]);
    }


    cout << ans;


    return 0;
}