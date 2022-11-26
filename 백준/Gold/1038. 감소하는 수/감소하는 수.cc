#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int n;
int cnt = 0;
bool check = false;
vector<ll> v;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;


    for (int i = 1; i <= 1023; i++) {
        ll num = 0;
        int tmp = i;

        for (int idx = 9; idx >= 0; idx--) {
            if (tmp % 2 == 1) {
                num = 10 * num + idx;
            }
            tmp /= 2;
        }
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    if (n > 1022) {
        cout << -1;
    }else
        cout << v[n];


    return 0;
}