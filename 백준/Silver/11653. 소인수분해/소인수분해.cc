#include <iostream>


using namespace std;

int not_prime[10000001] = {1, 1, 0};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;
    int div_num = 2;
    cin >> n;

    while (n != 1) {

        if (n % div_num == 0) {
            cout << div_num << "\n";
            n /= div_num;
        }else{
            div_num++;
        }

    }


    return 0;
}