#include <iostream>


using namespace std;

int not_prime[500000] = {1, 1, 0};

void solve(){

    for (int i = 2; i <= 500000; i++) {

        if (!not_prime[i]) {

            for (int j = 2 * i; j <= 500000; j += i) {

                not_prime[j] = 1;

            }
        }

    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    solve();


    while (1) {
        int num;

        int cnt = 0;
        cin >> num;

        if (num == 0) {
            break;
        }

        for (int i = num + 1; i <= num * 2; i++) {

            if (!not_prime[i]) {
                cnt++;
            }

        }

        cout << cnt << "\n";

    }



    return 0;
}