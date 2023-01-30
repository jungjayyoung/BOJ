#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int n, m;
char board[51][51];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int minn = min(n, m);

    minn--;
    for (int y = 0; y < n; y++) {

        string str;
        cin >> str;
        for (int x = 0; x < m; x++) {
            board[y][x] = str[x];
        }
    }

    int ans = 0;
    for (int l = minn; l >= 0; l--) {
        for (int y = 0; y + l < n; y++) {
            for (int x = 0; x + l < m; x++) {
                if (board[y][x] == board[y][x + l]
                    && board[y][x] == board[y + l][x]
                    && board[y][x] == board[y + l][x + l]) {
                    cout << (l + 1) * (l + 1);
                    return 0;
                }
            }
        }
    }




    return 0;
}