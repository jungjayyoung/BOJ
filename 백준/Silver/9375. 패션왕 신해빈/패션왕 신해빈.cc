#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int t, n;
typedef long long ll;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> t;

    while (t--) {

        ll type[32];
        map<string,int> mp;

        cin >> n;
        fill(type, type + n + 1, 0);

        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            mp[s2]++;

        }

        ll ans = 1;
        map<string,int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            ans *= (1 + it->second);
        }
        ans--;

        cout << ans << "\n";

    }

    return 0;
}