#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
vector<pair<string,int>> vv;

bool cmp(pair<string, int> &a, pair<string, int> &b) {

    if (a.second != b.second) {
        return a.second > b.second;
    }else{
        if (a.first.length() != b.first.length()) {
            return a.first.length() > b.first.length();
        } else {
            return a.first < b.first;
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.size() >= m) {
            v.push_back(s);
        }

    }


    sort(v.begin(),v.end());

    string cur = v[0];
    vv.push_back({cur, 1});
    for (int i = 1; i < v.size(); i++) {

        if (cur == v[i]) {
            vv[vv.size() - 1].second++;
        }else{
            cur = v[i];
            vv.push_back({cur, 1});
        }
    }

    sort(vv.begin(),vv.end(),cmp);
    for (int i = 0; i < vv.size(); i++) {
        cout << vv[i].first << "\n";
    }

    return 0;
}