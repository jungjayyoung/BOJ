#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

string a,b,c;

queue<pair<string,int>> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    cin >> a >> b;

    c = a;

    int ans = 123456;
    int cnt = 0;
    bool check = false;
    // 1. 첫번째 전구를 누른다
    cnt = 1;
    if(a[0] == '1') {
        a[0] = '0';
    }else{
        a[0] = '1';
    }

    if (a[1] == '1') {
        a[1] = '0';
    }else{
        a[1] = '1';
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1] != b[i - 1]) {
            cnt++;
            a[i - 1] = b[i - 1];
            if (a[i] == '1') {
                a[i] = '0';
            }else{
                a[i] = '1';
            }

            if (i + 1 < n) {
                if (a[i + 1] == '1') {
                    a[i + 1] = '0';
                }else{
                    a[i + 1] = '1';
                }
            }
        }
    }

    if (a == b) {
        check = true;
        ans = cnt;
    }
    //2. 첫번째 전구를 안 누른 경우
    cnt = 0;

    for (int i = 1; i < n; i++) {
        if (c[i - 1] != b[i - 1]) {
            cnt++;
            c[i - 1] = b[i - 1];
            if (c[i] == '1') {
                c[i] = '0';
            }else{
                c[i] = '1';
            }

            if (i + 1 < n) {
                if (c[i + 1] == '1') {
                    c[i + 1] = '0';
                }else{
                    c[i + 1] = '1';
                }
            }
        }
    }
    if (c == b) {
        check = true;
        ans = min(ans, cnt);
    }


    if (!check) {
        cout << -1;
    }else{
        cout << ans;
    }






}