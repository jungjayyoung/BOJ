#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string s;
vector<string> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> s;

    for(int i=0;i<s.size();i++){
        string tmp;
        tmp = s.substr(i);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(auto &i : v){
        cout << i << '\n';
    }





    return 0;
}
