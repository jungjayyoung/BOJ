#include <iostream>
#include <string>

using namespace std;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int bb = 0;
    int rr = 0;

    string str;

    cin >> n;
    cin >> str;
    bool b_check = false;
    bool r_check = false;

    for (int i = 0; i < str.size(); i++) {

        if (str[i] == 'B') {

            if (!b_check) {
                bb++;
                b_check = true;
                r_check = false;
            }

        } else if (str[i] == 'R') {
            if (!r_check) {
                rr++;
                r_check = true;
                b_check = false;
            }

        }
    }
    int ans = 0;

    if (bb <= rr) {
        ans += bb + 1;
    }else{
        ans += rr + 1;
    }

    cout << ans;


    return 0;
}