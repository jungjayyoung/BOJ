#include <iostream>


using namespace std;

int t;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;


    while (t--) {
        cin >> n;

        int idx = 0;
        while (n) {

            if (n % 2 == 1) {
                cout << idx << " ";
            }
            n = n / 2;

            idx++;
        }

        cout << "\n";

    }

    return 0;
}