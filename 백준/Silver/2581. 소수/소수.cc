#include <iostream>


using namespace std;


int not_prime[100000] = {1,1,0};

void solve(){

    for (int i = 2; i <= 10000; i++) {

        if (!not_prime[i]) {

            for (int j = i * 2; j <= 10000; j += i) {
                not_prime[j] = 1;
            }
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    int m, n;

    int sum = 0;
    bool check = false;

    cin >> m >> n;

    for (int i = m; i <= n; i++) {

        if (!not_prime[i]) {
            sum += i;
            check = true;
        }

    }

    if (!check) {
        cout << -1;
        return 0;
    }


    cout << sum << "\n";

    for (int i = m; i <= n; i++) {

        if (!not_prime[i]) {
            cout << i << "\n";
            break;
        }

    }



    return 0;
}