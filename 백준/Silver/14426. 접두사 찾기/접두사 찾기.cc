#include <iostream>
#include <string>
#include <vector>
using namespace std;


int n, m;
vector<string> v;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;


    for (int i = 0; i < n; i++) {

        string s;
        cin >> s;
        v.push_back(s);

    }

    int num = 0;

    for (int i = 0; i < m; i++) {

        string s;
        cin >> s;

        for (int j = 0; j < n; j++) {

            if (v[j].find(s) == 0) {
                num++;
                break;
            }
        }


    }

    cout << num;

    return 0;
}