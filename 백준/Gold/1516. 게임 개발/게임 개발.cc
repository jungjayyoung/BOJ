#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int n;
int time_consume[501];
int inDegree[501];
int cache[501];
vector<int> v[501];

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

    cin >> n;


    for (int i = 1; i <= n; i++) {
        cin >> time_consume[i];
        while (1) {
            int b;
            cin >> b;
            if (b == -1) {
                break;
            }
            v[b].push_back(i);
            inDegree[i]++;
        }
    }

    solve();

    for (int i = 1; i <= n; i++) {
        cout << cache[i] << "\n";
    }

    return 0;
}