#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


vector<char> v;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;


    while (t--) {

        string str;

        cin >> str;

        for (int i = 0; i < str.size(); i++) {
            v.push_back(str[i]);
        }
        bool check = false;
        //sort(v.begin(), v.end());

        do {
            string tmp;

            for (int i = 0; i < v.size(); i++) {
                tmp += v[i];
            }

            if (check) {
                cout << tmp << "\n";
                check = false;
                break;
            }

            if (tmp == str) {
                check = true;
            }


        } while (next_permutation(v.begin(), v.end()));

        if (check) {
            cout << str << "\n";
        }
        v.clear();
    }


    return 0;
}