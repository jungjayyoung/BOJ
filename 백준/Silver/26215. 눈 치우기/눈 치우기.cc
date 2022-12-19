#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int cnt = 0;

    while (v[n - 1] > 0) {

        cnt++;
        if (n - 1 >= 0 && v[n - 1] > 0) {
            v[n - 1]--;
        }

        if (n - 2 >= 0 && v[n - 2] > 0) {
            v[n - 2]--;
        }

        sort(v.begin(), v.end());

    }

    if (cnt > 1440) {
        cout << -1;
    }else
        cout << cnt;

    return 0;
}