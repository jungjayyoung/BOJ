#include <iostream>
#include <algorithm>

using namespace std;

int n;

int op[4];
int arr[13];
int minn,maxx;


void bt(int idx,int sum){

    if (idx >= n) {

        minn = min(minn, sum);
        maxx = max(maxx, sum);

        return;
    }

    // +, - , *, /
    for (int i = 0; i < 4; i++) {

        if (op[i] > 0) {
            op[i]--;
            if (i == 0) {
                bt(idx + 1, sum + arr[idx]);
            } else if (i == 1) {
                bt(idx + 1, sum - arr[idx]);
            } else if (i == 2) {
                bt(idx + 1, sum * arr[idx]);
            } else if (i == 3) {
                bt(idx + 1, sum / arr[idx]);
            }
            op[i]++;
        }

    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    for (int tt = 1; tt <= t; tt++) {

        cin >> n;


        for (int i = 0; i < 4; i++) {
            cin >> op[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }


        int sum = arr[0];
        minn = 123456789;
        maxx = -123456789;

        bt(1, sum);

        cout << "#" << tt << " " << abs(maxx - minn) << "\n";

    }



    return 0;
}