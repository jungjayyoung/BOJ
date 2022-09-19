#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int not_prime[10000000] ={1,1,0,};


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 4; i <= 8000000; i += 2) {
        not_prime[i] = 1;
    }
    for (int i = 3; i <= sqrt(8000000); i++) {

        if (not_prime[i] == 0) {

            for (int j = i * i; j <= 8000000; j += i + i) {
                not_prime[j] = 1;
            }

        }

    }

    int cnt = 0;

    for (int i = 2; i <= 8000000; i++) {

        if (not_prime[i] == 0) {
            cnt++;
            if (cnt == n) {
                cout << i;
                break;
            }
        }
    }

    return 0;
}