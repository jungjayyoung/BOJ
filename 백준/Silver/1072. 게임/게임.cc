#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll x, y;

ll start;
int ans = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y;

    start = (y * 100) / x;


    if (start < 99) {

        while (true) {
            x += 100;
            y += 100;
            ans += 100;

            if (((y * 100) / x) != start) {
                break;
            }
        }

        while (true) {
            x--;
            y--;
            ans--;
            if (((y * 100) / x) == start) {
                break;
            }
        }
        cout << ans + 1;

    }else
        cout << -1;

    return 0;
}

