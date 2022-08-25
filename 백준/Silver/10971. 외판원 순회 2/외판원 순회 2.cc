#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int w[11][11];
int n;
int cost = 0;
int minn = 123456789;
int visited[11];
vector<int> v;

void bt(int cnt){


    if (cnt == n) {

        
        int cost = 0;

        int pre = v[0];
        for (int i = 1; i < v.size(); i++) {
            if(w[pre][v[i]] == 0) return;
            cost += w[pre][v[i]];
            pre = v[i];

        }
        if(w[pre][v[0]] == 0) return;
        cost += w[pre][v[0]];

        minn = min(minn, cost);
        return;
    }

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {
            visited[i] = 1;
            v.push_back(i);
            bt(cnt + 1);
            v.pop_back();
            visited[i] = 0;
        }

    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }


    bt(0);

    cout << minn;
    return 0;
}