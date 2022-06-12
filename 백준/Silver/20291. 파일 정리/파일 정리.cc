#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> s;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;


    for (int i = 0; i < n; i++) {
        string str;
        string tmp;
        cin >> str;

        int idx = str.find('.');

        tmp = str.substr(idx + 1, str.size() - idx - 1);
        s.push_back(tmp);

    }

    sort(s.begin(), s.end());

    string cur = s[0];
    int cnt = 1;
    for (int i = 1; i < s.size(); i++) {

        if (cur == s[i]) {
            cnt++;
        }else{

            cout << cur << " " << cnt << "\n";
            cur = s[i];
            cnt = 1;
        }

    }


    if (s[s.size() - 1] != s[s.size() - 2]) {
        cout << s[s.size()-1] << " " << 1;
    }else if(s[s.size() - 1] == s[s.size() - 2]){
        cout << s[s.size()-1] << " " << cnt;
    }

    return 0;
}