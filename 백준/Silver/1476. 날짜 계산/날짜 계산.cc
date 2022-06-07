#include <iostream>


using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int e, s, m;

    cin >> e >> s >> m;

    int cnt = 1;

    int a = 1;
    int b = 1;
    int c = 1;

    while (1) {


        if (a == e && b == s && c == m) {
            break;
        }
        a++;
        b++;
        c++;

        if (a > 15) {
            a= 1;
        }

        if (b > 28) {
            b = 1;
        }

        if (c > 19) {
            c = 1;
        }

        cnt++;

    }



    cout << cnt;



    return 0;
}