#include <iostream>
#include <algorithm>

using namespace std;

int score[5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {

        int maxx = -1;
        int minn = 100;
        int max_check = false;
        int min_check = false;

        for (int i = 0; i < 5; i++) {
            cin >> score[i];
            maxx = max(maxx, score[i]);
            minn = min(minn, score[i]);
        }
        int sum = 0;
        int max2 = -1;
        int min2 = 100;

        for (int i = 0; i < 5; i++) {
            if (!max_check && score[i] == maxx) {
                max_check = true;
                continue;
            }
            if (!min_check && score[i] == minn) {
                min_check = true;
                continue;
            }
            sum += score[i];
            max2 = max(max2, score[i]);
            min2 = min(min2, score[i]);
        }


        if ((max2 - min2) >= 4) {
            cout << "KIN";
        }else
            cout << sum;

        cout << "\n";

    }

    return 0;
}