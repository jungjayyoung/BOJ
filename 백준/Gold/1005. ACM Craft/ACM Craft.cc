#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> v[1001];


int time_consume[1001];
int cache[1001];
int inDegree[1001];
int n, k, w;

void solve(){

    queue<int> q;

    for (int i = 1; i <= n; i++) {

        if (inDegree[i] == 0) {
            q.push(i);
            cache[i] = time_consume[i];
        }

    }


    while (!q.empty()) {

        int cur_build = q.front();

        q.pop();


        for (int i = 0; i < v[cur_build].size(); i++) {
            int next_build = v[cur_build][i];

            if (inDegree[next_build] - 1 == 0) {

                q.push(next_build);
            }

            inDegree[next_build]--;
            cache[next_build] = max(cache[next_build], cache[cur_build] + time_consume[next_build]);
        }

    }



}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;


    while (t--) {
        fill(time_consume, time_consume + 1000, 0);
        fill(cache, cache + 1000, 0);
        fill(inDegree, inDegree + 1000, 0);



        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> time_consume[i];
        }

        for (int i = 0; i < k; i++) {

            int x, y;
            cin >> x >> y;

            v[x].push_back(y);
            inDegree[y]++;

        }

        cin >> w;

        solve();



        cout << cache[w] << "\n";


        for (int i = 1; i <= n; i++) {

            v[i].clear();
        }
    }


    return 0;
}