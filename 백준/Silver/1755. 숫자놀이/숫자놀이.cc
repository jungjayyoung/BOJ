#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;


vector<string> v;
vector<pair<string,string>> ans;

string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n;

    cin >> m >> n;


    for (int i = m; i <= n; i++) {

        v.push_back(to_string(i));

    }


    for (int i = 0; i < v.size(); i++) {

        string tmp = "";

        for (int j = 0; j < v[i].size(); j++) {

            tmp += num[v[i][j] - '0'];

        }
        ans.push_back({tmp, v[i]});


    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {

        cout << stoi(ans[i].second) << " ";
        if ((i + 1) % 10 == 0) {
            cout << "\n";
        }
    }


    return 0;
}