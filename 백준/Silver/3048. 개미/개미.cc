#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int alp[27];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n1, n2;

    string s, s2;
    string s1;
    string ans;



    cin >> n1 >> n2;
    cin >> s1 >> s2;

    for (int i = 0; i < s2.size(); i++) {
        alp[s2[i] - 'A'] = 1;
    }

    reverse(s1.begin(), s1.end());

    ans = s1 + s2;
    int tt;

    cin >> tt;

    while (tt--) {


        for (int i = 0; i < ans.size() - 1; i++) {
            if (alp[ans[i] - 'A'] < alp[ans[i + 1] - 'A']) {
                swap(ans[i], ans[i + 1]);
                i++;
            }
        }


    }

    cout << ans;

    return 0;
}