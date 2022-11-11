#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;


string s,t;
bool check = false;
int a1 = 0,b1 = 0,a2 = 0,b2 = 0;

void dfs(string cur){




    if (cur.size() == s.size()) {

        if (cur == s) {
            check = true;
        }

        return;
    }
    if (cur.at(cur.size() - 1) == 'A') {
        dfs(cur.substr(0, cur.size() - 1));
    }

    if (cur.at(0) == 'B') {
        reverse(cur.begin(), cur.end());
        dfs(cur.substr(0, cur.size() - 1));
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> s >> t;


    dfs(t);

    if (check) {
        cout << 1;
    }else
        cout << 0;


    return 0;
}