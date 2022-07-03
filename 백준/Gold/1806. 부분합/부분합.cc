#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int arr[100001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] >= s) {
            cout << 1;
            return 0;
        }
    }

    int ss = 0;
    int ee = 1;
    int ans = 1000000;
    int sum = arr[0] + arr[1];

    while (ss <= n - 1) {

        if (sum >= s) {
            ans = min(ans, ee - ss + 1);

            sum -= arr[ss];
            ss++;

        } else if(sum < s){
            if (ee <= n - 2) {
                ee++;
                sum += arr[ee];
            }else
                break;
        }
    }

    if (ans == 1000000) {
        cout << 0;
    }else
        cout << ans;
    return 0;
}