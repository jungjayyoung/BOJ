#include <iostream>
#include <string>

using namespace std;

bool solve(string s, int st, int end){

    if (st >= end) {
        return true;
    }

    int left = st;
    int right = end;

    while (left < right) {
        if (s[left++] == s[right--]) {
            return false;
        }
    }

    // 분할 정복
    return solve(s, st, right - 1);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;

        if (str.size() % 2 == 0) {
            cout << "NO\n";
            continue;
        }

        if (solve(str, 0, str.size() - 1) == 1) {
            cout << "YES" << "\n";
        }else
            cout << "NO" << "\n";

    }


}