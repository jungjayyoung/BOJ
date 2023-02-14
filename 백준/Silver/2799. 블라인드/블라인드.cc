#include <iostream>
#include <string>

using namespace std;


int m, n;

string ss[502];
int ans[5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < 5 * m + 1; i++) {
        cin >> ss[i];
    }


    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            int cnt = 0;
            for (int l = k * 5 + 1; l < k * 5 + 5; l++) {
                if (ss[l][i * 5 + 1] == '*') {
                    cnt++;
                }

            }
            ans[cnt]++;
        }
    }


    for (int i = 0; i < 5; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}