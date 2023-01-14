#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int n;
vector<ll> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    if (v.size() == 1) {
        cout << v[0] * v[0];
    } else {
        cout << v.front() * v.back();
    }



    return 0;
}