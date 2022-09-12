#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>
using namespace std;

unordered_set<string> keyword;
unordered_set<string> essay;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        keyword.insert(a);
    }

    char sep = ',';
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        istringstream iss(s);
        string tmp;
        while (getline(iss, tmp, sep)) {

            if (keyword.find(tmp) != keyword.end()) {
                essay.insert(tmp);
            }

        }


        cout << keyword.size() - essay.size() << "\n";
    }

    return 0;
}