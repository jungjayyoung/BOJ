#include <iostream>
#include <queue>
#include <vector>



using namespace std;


int n, k;
int visited[100001];
int parent[100001];
vector<int> v;


void bfs(){

    queue<pair<int,int>> q;

    q.push({n, 0});
    visited[n] = 1;

    while (!q.empty()) {

        int cur = q.front().first;
        int cnt = q.front().second;


        q.pop();


        if (cur == k) {

            while (cur != n) {

                v.push_back(cur);
                cur = parent[cur];
            }
            v.push_back(n);
            cout << cnt << "\n";
            return;
        }


        if (cur - 1 >= 0 && !visited[cur - 1]) {
            q.push({cur - 1, cnt + 1});
            parent[cur - 1] = cur;
            visited[cur - 1] = 1;
        }

        if (cur + 1 <= 100000 && !visited[cur + 1]) {
            q.push({cur + 1, cnt + 1});
            parent[cur + 1] = cur;
            visited[cur + 1] = 1;
        }

        if (cur != 0 && cur * 2 <= 100000 && !visited[2 * cur]) {
            q.push({2 * cur, cnt + 1});
            parent[2 * cur] = cur;
            visited[2 * cur] = 1;
        }

    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> k;


    bfs();

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }


    return 0;
}