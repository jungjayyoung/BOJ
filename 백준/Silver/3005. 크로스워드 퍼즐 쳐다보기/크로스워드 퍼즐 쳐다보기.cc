#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


char board[21][21];
vector<string> v;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int r,c;

    cin >> r >> c;


    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            board[i][j] = s[j];
        }
    }

    for (int y = 0; y < r; y++) {

        string ss;
        bool check = false;
        for (int x = 0; x < c; x++) {

            if(board[y][x] != '#'){
                ss.push_back(board[y][x]);
                check = true;
            }else{
                if (!ss.empty() && ss.length() >= 2) {
                    v.push_back(ss);
                }
                ss = "";
                check = false;
            }

        }
        if (check && !ss.empty() && ss.length() >= 2) {
            v.push_back(ss);
        }

    }

    for (int x = 0; x < c; x++) {

        string ss;
        bool check = false;
        for (int y = 0; y < r; y++) {

            if(board[y][x] != '#'){
                ss.push_back(board[y][x]);
                check = true;
            }else{
                if (!ss.empty() && ss.length() >= 2) {
                    v.push_back(ss);
                }
                ss = "";
                check = false;
            }

        }
        if (check && !ss.empty() && ss.length() >= 2) {
            v.push_back(ss);
        }

    }

    sort(v.begin(), v.end());

    cout << v[0];
    return 0;
}