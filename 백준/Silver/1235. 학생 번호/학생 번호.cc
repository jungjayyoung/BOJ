#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> s;
set<string> ss;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        s.push_back(a);
    }


    unsigned int ans = s[0].size();

    while (ans--) {

        for (int i = 0; i < s.size(); i++) {
            ss.insert(s[i].substr(s[i].size() - ans));
        }

        if (ss.size() != s.size()) {
            break;
        }

        ss.clear();
    }

    cout << ans + 1;



    return 0;
}