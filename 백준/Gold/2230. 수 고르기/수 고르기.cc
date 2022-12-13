#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<ll> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int i = 0;
    int j = 0;
    ll ans = 9876543211;

    while (j < n && i < n) {

        if (abs(v[i] - v[j]) >= m) {
            
            if(ans > abs(v[i] - v[j])){
                ans = abs(v[i] - v[j]);
            }
            i++;
            if(i >= j)
                j++;
        }else{
            j++;
        }

    }


    cout << ans;


}