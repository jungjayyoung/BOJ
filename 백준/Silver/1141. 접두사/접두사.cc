#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;


vector<string> v;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;
    int ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {

        string cur = v[i];
        bool check = false;

        for (int j = i + 1; j < v.size(); j++) {

            if (cur == v[j].substr(0, cur.size())) {
                check = true;
                break;
            }

        }

        if (!check) {
            ans++;
        }

    }

    cout << ans;

    return 0;
}