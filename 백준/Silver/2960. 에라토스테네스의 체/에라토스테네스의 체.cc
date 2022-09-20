#include <iostream>



using namespace std;

int n,k;
int not_prime[100000] ={1,1,0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);




    cin >> n >> k;

    int cnt = 0;

    for (int i = 2; i <= n; i++) {

        if (not_prime[i] == 0) {

            cnt++;
            if (cnt >= k) {
                cout <<  i;
                return 0;
            }
            for (int j = 2 * i; j <= n; j += i) {

                if (not_prime[j] == 0) {
                    not_prime[j] = 1;
                    cnt++;

                    if (cnt >= k) {
                        cout <<  j;
                        return 0;
                    }
                }




            }
        }
    }

    return 0;
}