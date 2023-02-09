#include <iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (1) {
        int n, k;
        cin >> n >> k;
        if(cin.eof()) break;

        int sum = 0;

        int stamp = 0;

        while (n) {

            sum += n;
            stamp += n;
            n = 0;
            n += stamp / k;
            stamp %= k;
        }

        cout << sum << "\n";


    }


    return 0;
}