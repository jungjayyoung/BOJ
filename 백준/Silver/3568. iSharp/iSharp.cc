#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    string start;

    getline(cin, str);

    string tmp;
    for (int i = 0; i < str.size(); i++) {

        if (str[i] != ' ' && str[i] != ',' && str[i] != ';') {
            tmp += str[i];
        }else{
            if(!tmp.empty()){
                v.push_back(tmp);
            }

            tmp = "";
        }
    }

    for (int i = 1; i < v.size(); i++) {
        string a;
        string b;

        for (int j = 0; j < v[i].size(); j++) {
            if(isalpha(v[i][j])){
                a += v[i][j];
            } else {
                b += v[i][j];
            }

        }
        reverse(b.begin(), b.end());

        for (int j = 0; j < b.size(); j++) {
            if (b[j] == '[') {
                b[j] = ']';
            } else if (b[j] == ']') {
                b[j] = '[';
            }
        }

        cout << v[0] << b << " " << a << ';' << "\n";

    }


    return 0;
}
