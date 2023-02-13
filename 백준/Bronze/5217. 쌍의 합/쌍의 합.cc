#include <iostream>


using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >> t;


    for (int i = 1; i <= t; i++) {

        cin >> n;
        cout << "Pairs for " << n << ": ";

        for (int j = 1; j <= n; j++) {
            int j2 = n - j;

            if(j >= j2) break;
            if(j != 1) cout << ", ";
            cout << j << " " << j2;
        }

        cout << "\n";

    }

    return 0;
}