#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n;
int visited[51];
vector<int> v[51];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;


    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == 'Y') {
                v[i].push_back(j);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {

        queue<pair<int,int>> q;
        fill(visited, visited + n + 1, 0);

        q.push({i, 0});
        visited[i] = 1;

        while (!q.empty()) {

            int cur = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if (cnt > 2) {
                break;
            }
            visited[cur] = 1;


            for (int j = 0; j < v[cur].size(); j++) {
                int next = v[cur][j];

                if (!visited[next]) {
                    q.push({next, cnt + 1});
                }
            }


        }

        int num = 0;

        for (int j = 0; j < n; j++) {
            if (i != j && visited[j]) {
                num++;
            }
        }

        ans = max(ans, num);


    }

    cout << ans;


    return 0;
}