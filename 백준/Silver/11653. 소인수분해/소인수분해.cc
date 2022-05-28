#include <iostream>


using namespace std;

int not_prime[10000001] = {1, 1, 0};

void solve(){


    for (int i = 2; i <= 10000000; i++) {

        if (!not_prime[i]) {

            for (int j = 2 * i; j <= 10000000; j += i) {

                not_prime[j] = 1;

            }

        }
    }



}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    int n;
    int div_num = 2;
    cin >> n;

    while (n != 1) {

        if (!not_prime[div_num] && n % div_num == 0) {
            cout << div_num << "\n";
            n /= div_num;
        }else{
            div_num++;
        }
    }


    return 0;
}