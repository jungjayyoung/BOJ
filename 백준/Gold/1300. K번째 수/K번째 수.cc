#include <iostream>
#include <algorithm>

using namespace std;


int n, k;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;


    int start = 1;
    int end = k;
    int ans;

    while (start <= end) {

        int mid = (start + end) / 2;

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += min(n, mid / i);
        }

        if (cnt < k) {
            start = mid + 1;
        } else{
            ans = mid;
            end = mid - 1;
        }


    }

    cout << ans;


    return 0;
}