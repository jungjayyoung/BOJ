#include <iostream>
#include <algorithm>

using namespace std;


int ans = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sum = 0;
    for (int i = 0; i < 4; i++) {
        int a, b;
        cin >> a >> b;

        sum = sum + b - a;
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}