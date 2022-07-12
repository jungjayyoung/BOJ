#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
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
        sort(v.begin(), v.end());

        do {
            string tmp;

            for (int i = 0; i < v.size(); i++) {
                tmp += v[i];
            }
            cout << tmp << "\n";

        } while (next_permutation(v.begin(), v.end()));

        v.clear();

    }


    return 0;
}