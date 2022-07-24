#include <iostream>
#include <string>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int l_cnt = 0;
    int r_cnt = 0;
    int sum = 0;
    int ans = 0;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '(') {
            l_cnt++;
            sum--;
        } else if (s[i] == ')') {

            r_cnt++;
            sum++;

        }
        if (sum > 0) {
            cout << r_cnt;
            return 0;
        }
        if (sum == 0) {
            l_cnt = 0;
        }

    }

    cout << l_cnt;


    return 0;
}