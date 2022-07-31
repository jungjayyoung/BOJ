#include <iostream>
#include <string>
#include <numeric>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >> t;

    while (t--) {

        string s;
        string inf;
        string not_inf;
        string total_num;
        cin >> s;
        ll idx = s.find('(');
        if(idx != -1) {
            inf = s.substr(idx+ 1,(s.size() - idx - 2));
        }

        bool check = false;
        bool check2 = false;
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '.') {
                check = true;
                continue;
            }
            if(s[i] == '(' || s[i] == ')'){
                check2 = true;
                continue;
            }

            if (check) {
                total_num = total_num + s[i];
            }
            if (check && !check2) {
                not_inf = not_inf + s[i];
            }
        }

        string d;
        ll down, up;

        // 순환소수일 때
        if (!inf.empty()) {
            for (int j = 0; j < inf.size(); j++) {
                d = d + '9';
            }

            if (!not_inf.empty()) {
                for (int j = 0; j < not_inf.size(); j++) {
                    d = d + '0';
                }
            }

            down = stoll(d);
            
            if (!not_inf.empty()) {
                up = stoll(total_num) - stoll(not_inf);
            }else{
                up = stoll(total_num);
            }


            ll a = gcd(down, up);
            down = down / a;
            up = up / a;

            cout << up << '/' << down;

        }else{
            // 순환소수가 아닐 때

            d = d + '1';

            if (!not_inf.empty()) {
                for (int i = 0; i < not_inf.size(); i++) {
                    d = d + '0';
                }
            }

            up = stoll(total_num);
            down = stoll(d);
            ll a = gcd(up, down);

            up = up / a;
            down = down / a;

            cout << up << '/' << down;

        }

        cout << "\n";
    }







    return 0;
}
