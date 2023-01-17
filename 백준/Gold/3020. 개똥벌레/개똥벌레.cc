#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, h;

int bt[500001];
int tp[500001];
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> h;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (i % 2 == 0) {
            bt[num]++;
        }else
            tp[num]++;
    }

    // 종유석과 석순의 누적합 구하기
    for (int i = h; i >= 2; i--) {
        tp[i - 1] += tp[i];
        bt[i - 1] += bt[i];
    }

    // 벽이 중복 되는 위치의 개수 합(=뚫어야 되는 벽의 개수)을 벡터에 넣는다.
    // 합이 작다는 것은 뚫어여 되는 벽의 개수가 적다는 뜻
    for (int i = 1; i <= h; i++) {
        v.push_back(bt[i] + tp[h + 1 - i]);
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[0] == v[i]) {
            ans++;
        }
    }

    cout << v[0] << " " << ans;
    
    return 0;
}