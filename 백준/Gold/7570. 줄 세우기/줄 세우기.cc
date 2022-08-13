#include <iostream>
#include <algorithm>

using namespace std;

//1. vector STL에 있는 lower_bound, upper_bound는 찾으려는 키값보다 같거나 큰 숫자가
// 배열 몇 번째에 처음 등장하는지 찾을 때 사용할 수 있다.

int arr[1000001];
int dp[1000001];

int ans = 0;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];

        dp[arr[i]] += dp[arr[i] - 1] + 1;
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }

    cout << n - ans;



    return 0;
}