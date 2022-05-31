#include <iostream>


using namespace std;


int notPrime[20001] = {1, 1, 0};

void solve(){

    for (int i = 2; i <= 20000; i++) {

        if (!notPrime[i]) {

            for (int j = i * 2; j <= 20000; j += i) {

                notPrime[j] = 1;
            }

        }

    }

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    solve();


    while (t--) {
        int n;

        cin >> n;


        for (int i = n / 2; i >= 2; i--) {
            if (!notPrime[i] && !notPrime[n - i]) {
                cout << i << " " << n - i << "\n";
                break;
            }

        }
    }


    return 0;
}