#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    ll sum = 0;

    int idx = 1;
    for (int i = 0; i < n; i++) {
        sum += abs(v[i] - idx++);
    }

    cout << sum;

}