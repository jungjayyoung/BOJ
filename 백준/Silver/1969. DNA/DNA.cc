#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string str[1001];
string ans_str;
int n,m;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    int a_cnt = 0;
    int t_cnt = 0;
    int g_cnt = 0;
    int c_cnt = 0;
    int maxx = 0;
    string s = "";
    for (int i = 0; i < m; i++) {
        a_cnt = 0;
        t_cnt = 0;
        g_cnt = 0;
        c_cnt = 0;
        for (int j = 0; j < n; j++) {

            if (str[j][i] == 'T') {
                t_cnt++;
            }else if(str[j][i] == 'A'){
                a_cnt++;
            }else if(str[j][i] == 'G'){
                g_cnt++;
            }else if(str[j][i] == 'C'){
                c_cnt++;
            }
        }

        maxx = max(t_cnt, max(a_cnt, max(g_cnt, c_cnt)));

        if (maxx == a_cnt) {

            s += 'A';

        } else if (maxx == c_cnt) {
            s += 'C';
        } else if (maxx == g_cnt) {
            s += 'G';
        } else if (maxx == t_cnt) {
            s += 'T';
        }


    }


    int ans = 0;
    for (int i = 0; i < n; i++) {


        int cnt = 0;
        for (int j = 0; j < m; j++) {

            if (s[j] != str[i][j]) {
                cnt++;
            }

        }

        ans += cnt;

    }


    cout << s << "\n";
    cout << ans;


    return 0;
}