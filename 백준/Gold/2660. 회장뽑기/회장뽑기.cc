#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[51];
int num[51];
vector<int> v[51];
int ans = 100;
int n;




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    while (1) {
        int a, b;

        cin >> a >> b;

        if (a == -1 && b == -1) {
            break;
        }

        v[a].push_back(b);
        v[b].push_back(a);

    }


    for (int i = 1; i <= n; i++) {

        queue<pair<int,int>> q;
        fill(visited, visited + n + 1, 0);

        q.push({i,0});
        visited[i] = 1;

        // 1. 회장의 조건
        // 다른 모든 회원들과 친구여야 한다.
        // 그런데 문제에서 입력값은 모든 회원들이 다 연결되어 있다고 한다. 따라서 따로 체크할 필요 없다.

        int tmp = -1;

        while (!q.empty()) {
            int cur = q.front().first;
            int cnt = q.front().second;

            q.pop();

            tmp = max(tmp, cnt);

            for (int j = 0; j < v[cur].size(); j++) {
                int nxt = v[cur][j];
                if (!visited[nxt]) {
                    visited[nxt] = 1;
                    q.push({nxt, cnt + 1});
                }
            }

        }

        ans = min(ans, tmp);
        num[i] = tmp;

    }

    int cntt = 0;

    for (int i = 1; i <= n; i++) {
        if (num[i] == ans) {
            cntt++;
        }
    }

    cout << ans << " " << cntt << "\n";

    for (int i = 1; i <= n; i++) {

        if (num[i] == ans) {
            cout << i << " ";
        }
    }


    return 0;
}