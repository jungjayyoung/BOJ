#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int n;
vector<pair<ll,ll>> v;

bool cmp(pair<int, int> a, pair<int, int> b){

    if (a.second != b.second) {
        return a.second > b.second;
    } else if (a.first != b.first) {
        return a.first > b.first;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        ll a,b;
        cin >> a >> b;
        v.push_back({a, b});
    }


    sort(v.begin(), v.end(), cmp);

    int ans = v[0].first - v[0].second;

    int e =v[0].second;
    int s = v[0].first;
    int next_e = e - s; // 놀 수 있는 최대 날짜

    for (int i = 1; i < n; i++) {
        e = v[i].second;
        s = v[i].first;

        if (next_e >= e) {
            next_e = e - s;
        } else if (next_e < e) {
            next_e = next_e - s;
        }

    }


    cout << next_e;






    return 0;
}