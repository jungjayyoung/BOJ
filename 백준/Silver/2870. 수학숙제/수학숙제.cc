#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
vector<string> ans;


bool cmp(string &s1, string &s2) {

    if(s1.size() == s2.size()) return s1 < s2;
    else
        return s1.size() < s2.size();

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;


    for (int i = 0; i < n; i++) {

        string str;
        cin >> str;
        string tmp;

        for (int j = 0; j < str.size(); j++) {
            if (str[j] >= '0' && str[j] <= '9') {
                tmp += str[j];
            }else{
                if (!tmp.empty()) {
                    v.push_back(tmp);
                }
                tmp = "";
            }
        }
        if (!tmp.empty()) {
            v.push_back(tmp);
        }
    }


    for (int i = 0; i < v.size(); i++) {

        while (1) {

            if (v[i].size() >= 2 && v[i][0] == '0') {
                v[i].erase(0, 1);
            }else{
                break;
            }
        }

    }

    sort(v.begin(), v.end(),cmp);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }



    return 0;
}