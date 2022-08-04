#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    string str;

    cin >> str;

    int one_cnt = 0;
    int zero_cnt = 0;
    bool one_check = false;
    bool zero_check = false;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0' && !zero_check) {
            zero_cnt++;
            zero_check = true;
            one_check = false;
        } else if (str[i] == '1' && !one_check) {
            one_cnt++;
            one_check = true;
            zero_check = false;
        }
    }

    cout << min(one_cnt, zero_cnt);

    return 0;
}