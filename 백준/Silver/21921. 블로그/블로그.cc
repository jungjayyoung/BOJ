#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int n, x;
int visiter[250001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> visiter[i];
    }

    int sum = 0;

    for (int i = 0; i < x; i++) {
        sum += visiter[i];
    }

    int s = 0;
    int e = x;

    int ans = sum;
    int cnt = 1;

    while (e < n) {
        sum -= visiter[s++];
        sum += visiter[e++];
        if (sum >= ans) {

            if (sum == ans) {
                cnt++;
            }else
                cnt = 1;
            ans = sum;
        }
    }

    if (ans == 0) {
        cout << "SAD";
    } else {
        cout << ans << "\n" << cnt;
    }

    return 0;
}