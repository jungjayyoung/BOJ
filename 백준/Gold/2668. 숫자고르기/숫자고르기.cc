#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v[101];
int visited[101];   // 이미 탐색된 노드 방문체크
int visited2[101];  // dfs 하면서 같은 노드를 방문했는지 표시하기 위한 배열 => 사이클 존재 확인 용도
bool cycle_check = false;
bool start_check = false;
int start = 0;

vector<int> ans;

void dfs(int num){


    visited[num] = 1;
    visited2[num] = 1;


    for (int i = 0; i < v[num].size(); i++) {
        int next = v[num][i];

        if (!visited[next]) {
            dfs(next);
        }else if(visited2[next]){
            cycle_check = true;
            start = next;
        }

    }

    if (cycle_check && num == start) {
        start_check = true;
        ans.push_back(num);
        return;
    }

    if (cycle_check && !start_check) {
        ans.push_back(num);
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        v[i].push_back(num);

    }


    for (int i = 1; i <= n; i++) {
        cycle_check = false;
        start_check = false;
        start = 0;
        if (!visited[i]) {
            fill(visited2, visited2 + n + 1, 0);
            dfs(i);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto i: ans) {
        cout << i << "\n";
    }


    return 0;
}