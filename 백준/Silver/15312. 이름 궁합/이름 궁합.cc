#include <iostream>
#include <string>
#include <vector>

using namespace std;


int alp[26] = {3, 2, 1, 2, 3,
3, 2, 3, 3, 2, 2, 1,
2, 2, 1, 2, 2, 2,
1, 2, 1, 1, 1, 2, 2, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;

    cin >> a >> b;

    string tmp = "";
    for (int i = 0; i < a.size(); i++) {

        tmp = tmp + a[i] + b[i];

    }


    vector<int> v;

    for (int i = 0; i < tmp.size() - 1; i++) {
        v.push_back(alp[tmp[i] - 'A'] + alp[tmp[i + 1] - 'A']);
    }


    vector<int> tmpp;

    while (1) {

        for (int i = 0; i < v.size() - 1; i++) {
            tmpp.push_back((v[i] + v[i + 1]) % 10);
        }

        if (tmpp.size() == 2) {
            cout << tmpp[0] << tmpp[1];
            return 0;
        }

        v.clear();
        v = tmpp;
        tmpp.clear();
    }

    return 0;
}