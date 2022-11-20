#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n, k;

int chosen[27];
vector<string> strs;
int ans = 0;

void bt(int idx,int cntt){

    if (cntt == k) {
        int cnt = 0;
        bool check;

        for (int i = 0; i < n; i++) {
            string cur = strs[i];
            check = false;
            for (int j = 0; j < cur.length(); j++) {
                if (chosen[cur[j] - 'a'] == 0) {
                    check = true;
                    break;
                }
            }

            if (!check) {
                cnt++;
            }

        }

        ans = max(ans, cnt);

        return;
    }


    for (int i = idx; i < 26; i++) {
        if(chosen[i] == 1) continue;
        chosen[i] = 1;
        bt(i+1, cntt + 1);
        chosen[i] = 0;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;


    chosen['a' - 'a'] = 1;
    chosen['c' - 'a'] = 1;
    chosen['t' - 'a'] = 1;
    chosen['i' - 'a'] = 1;
    chosen['n' - 'a'] = 1;


    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        strs.push_back(str);

    }

    if (k < 5) {
        cout << 0;
        return 0;
    }

    k = k - 5;


    bt(0, 0);


    cout << ans;


}