#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MOD 1000000007
using namespace std;

typedef long long ll;

int n, q;
ll house[1001];
vector<ll> v[1001];
int visited[1001];
bool check = false;


void dfs(ll num,ll cur_idx,ll goal){ // 현재 문자열 숫자, 목표 대문 번호

    visited[cur_idx] = 1;

    if (cur_idx == goal) {
        cout << num << "\n";
        check = true;
        return;
    }

    for (int i = 0; i < v[cur_idx].size(); i++) {
        int next_idx = v[cur_idx][i];
        if (!visited[next_idx]) {
            ll next_num = house[next_idx];
            int zero_cnt = int(log10(next_num)) + 1;

            ll tmp = 1;
            for (int j = 0; j < zero_cnt    ; j++) {
                tmp = (tmp * 10) % MOD;
            }
            ll zeroAddedNum = ((num % MOD) * (tmp % MOD)) % MOD;
            ll sum = (zeroAddedNum  + next_num % MOD) % MOD;
            dfs(sum, next_idx, goal);
        }
        if(check) {
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> house[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }


    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        fill(visited, visited + 1001, 0);
        check = false;
        dfs(house[a], a, b);
    }


    return 0;
}