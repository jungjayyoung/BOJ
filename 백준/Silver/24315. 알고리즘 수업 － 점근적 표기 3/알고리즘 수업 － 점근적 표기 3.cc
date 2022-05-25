#include <iostream>


using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a1, a0, f, c1, c2, n0;

    cin >> a1 >> a0;
    cin >> c1 >> c2;
    cin >> n0;

    bool check = false;

    for (int i = n0; i <= 100; i++) {
        f = a1 * i + a0;
        if (c1 * i <= f && f <= c2 * i) {

        }else{
            check = true;
            break;
        }
    }

    if (check) {
        cout << 0;
    }else
        cout << 1;


    return 0;
}
