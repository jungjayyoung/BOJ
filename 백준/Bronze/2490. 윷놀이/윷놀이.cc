#include <iostream>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 3; i++) {

        int one = 0;
        int zero = 0;

        for (int j = 0; j < 4; j++) {
            int num;
            cin >> num;
            if(num == 1) one++;
            else zero++;
        }
        if (zero == 1) {
            cout << "A";
        } else if (zero == 2) {
            cout << "B";
        } else if (zero == 3) {
            cout << "C";
        } else if (zero == 4) {
            cout << "D";
        } else if (one == 4) {
            cout << "E";
        }
        cout << "\n";
    }
    return 0;
}