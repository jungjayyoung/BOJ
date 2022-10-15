#include <iostream>
#include <numeric>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {

        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int tmp = lcm(m, n);

        for (; x <= tmp; x += m) {
            if((x-1) % n + 1 == y || x > tmp) break;
        }

        if(x > tmp) cout << -1 << "\n";
        else cout << x << "\n";


    }

    return 0;
}