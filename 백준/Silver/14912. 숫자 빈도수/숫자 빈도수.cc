#include <iostream>
#include <string>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    char d;

    cin >> n >> d;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        string s = to_string(i);

        for (int j = 0; j < s.size(); j++) {
            if (s[j] == d) {
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}