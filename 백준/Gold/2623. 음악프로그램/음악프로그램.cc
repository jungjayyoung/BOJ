#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n,m;
vector<int> v[1001];
vector<int> pd[101];
vector<int> ans;
int visited[1001];
int visited2[1001][1001];
int inDegree[1001];
bool check = false;


void solve(){

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            visited[i] = 1;
        }
    }
    
    while (!q.empty()) {

        int cur_singer = q.front();


        q.pop();
        ans.push_back(cur_singer);


        for (int i = 0; i < v[cur_singer].size(); i++) {

            int next_singer = v[cur_singer][i];

            if(inDegree[next_singer] - 1 == 0 ) {
                q.push(next_singer);
            }
            
            inDegree[next_singer]--;

        }

    }


}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;


    for (int i = 0; i < m; i++) {

        int cnt;
        cin >> cnt;

        for (int j = 0; j < cnt; j++) {
            int a;
            cin >> a;
            pd[i].push_back(a);
        }


    }

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < pd[i].size() - 1; j++) {

            int a = pd[i][j];
            int b = pd[i][j + 1];

            //중복 간선 에외 처리
            if (!visited2[a][b]) {
                visited2[a][b] = 1;
                v[a].push_back(b);
                inDegree[b]++;
            }


        }
    }

    solve();

    if (ans.size() != n) {
        check = true;
    }

    if (check) {
        cout << 0;
    }else{

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << "\n";
        }
    }

    return 0;
}