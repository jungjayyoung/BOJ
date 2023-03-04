#include <iostream>


using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;

    cin >> a >> b >> c;

    int n = 2;
    int bun = 0;
    int degi = 0;
    int ans = 0;


    while (1) {

        for (int i = 0; i < 4; i++) {

            if (i % 2 == 0) {
                bun++;
                if (c == 0 && bun == b) {
                    cout << ans;
                    return 0;
                }

            } else {
                degi++;
                if (c == 1 && degi == b) {
                    cout << ans;
                    return 0;
                }
            }
            ans++;
            if (ans == a) {
                ans = 0;
            }
        }

        // 뻔 * n 번
        for (int i = 0; i < n; i++) {
            bun++;
            if (c == 0 && bun == b) {
                cout << ans;
                return 0;
            }
            ans++;
            if (ans == a) {
                ans = 0;
            }
        }

        // 데기 * n 번
        for (int i = 0; i < n; i++) {
            degi++;
            if (c == 1 && degi == b) {
                cout << ans;
                return 0;
            }
            ans++;
            if (ans == a) {
                ans = 0;
            }
        }

        n++;

    }



    return 0;
}