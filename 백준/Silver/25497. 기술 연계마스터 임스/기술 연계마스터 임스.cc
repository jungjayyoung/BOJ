#include <iostream>
#include <string>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >>n;

    int scnt = 0;
    int lcnt = 0;

    int cnt = 0;

    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '1' && str[i] <= '9') {
            cnt++;
        }
        if (str[i] == 'L') {
            lcnt++;
        }
        if (str[i] == 'R') {
            if (lcnt > 0) {
                lcnt--;
                cnt++;
            } else {
                break;
            }
        }
        if (str[i] == 'S') {
            scnt++;
        }
        if (str[i] == 'K') {
            if (scnt > 0) {
                scnt--;
                cnt++;
            }else
                break;
        }
    }

    cout << cnt;

    return 0;
}