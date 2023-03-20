#include <iostream>
#include <string>
#include <algorithm>


using namespace std;


int n;

char map[101][101];
int visited[101][101];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

   cin >> n;

    for (int y = 0; y < n; y++) {
        string str;
        cin >> str;

        for (int x = 0; x < n; x++) {
            map[y][x] = str[x];
        }
    }

    int ans1 = 0;
    for (int y = 0; y < n; y++) {

        int cnt = 0;
        for (int x = 0; x < n; x++) {
            if (map[y][x] == '.') {
                cnt++;
            } else {
                if (cnt >= 2) {
                    ans1++;
                }
                cnt = 0;
            }
        }
        if (cnt >= 2) {
            ans1++;
        }
    }

    int ans2 = 0;

    for (int x = 0; x < n; x++) {

        int cnt = 0;
        for (int y = 0; y < n; y++) {
            if (map[y][x] == '.') {
                cnt++;
            } else {
                if (cnt >= 2) {
                    ans2++;
                }
                cnt = 0;
            }
        }

        if (cnt >= 2) {
            ans2++;
        }

    }

    cout << ans1 << " " << ans2;


    return 0;
}