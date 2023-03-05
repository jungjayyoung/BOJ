#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    
    for (int i = 0; i < n; i++) {

        int num;

        cin >> num;

        map<ll,ll> m;
        
        for (int j = 0; j < num; j++) {

            ll idx;
            cin >> idx;

            if (m.find(idx) == m.end()) {
                m.insert({idx, 1});
            }else{
                m[idx]++;
            }

        }

        bool check = false;
        for (auto j: m) {

            double res = (double)j.second / num * 100;
            if (res > 50) {
                cout << j.first << "\n";
                check = true;
                break;
            }

        }

        if (!check) {
            cout << "SYJKGW" << "\n";
        }
        
    }

    return 0;
}