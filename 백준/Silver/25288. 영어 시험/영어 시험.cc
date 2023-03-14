#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;

    cin >> n;
    cin >> s;

    string ans;

    for (int i = 0; i < n; i++) {
        ans += s;
    }

    cout << ans;


    return 0;
}