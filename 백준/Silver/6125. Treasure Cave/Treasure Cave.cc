#include <iostream>
#include <vector>

using namespace std;

int p, ns, t;

vector<int> v[5001];
vector<int> path;
bool check = false;
int ans = 0;

void dfs(int cur,int num){

    if (cur == t) {

        check = true;
        ans = num;
        return;
    }


    for (int i = 0; i < v[cur].size(); i++) {
        int next = v[cur][i];

        path.push_back(next);
        dfs(next,num + 1);
        if(check) return;
        path.pop_back();


    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> p >> ns >> t;

    for (int i = 0; i < ns; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(b);
        v[a].push_back(c);
    }

    path.push_back(1);
    dfs(1, 1);

    cout << ans << "\n";

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << "\n";
    }

}