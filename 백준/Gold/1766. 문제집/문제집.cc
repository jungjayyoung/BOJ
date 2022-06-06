#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int n,m;
vector<int> v[32001];
int inDegree[32001];



void solve(){
    priority_queue<int,vector<int>,greater<int>> pq;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }


    while (!pq.empty()) {

        int cur_subject = pq.top();


        pq.pop();

        cout << cur_subject << " ";

        for (int i = 0; i < v[cur_subject].size(); i++) {
            int next_subject = v[cur_subject][i];

            if (inDegree[next_subject] - 1 == 0) {
                pq.push(next_subject);
            }

            inDegree[next_subject]--;

        }

    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;


    for (int i = 0; i < m; i++) {

        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        inDegree[b]++;

    }

    solve();


    return 0;
}