#include <iostream>
#include <algorithm>

using namespace std;




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);



    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a[5];
        int b[5];
        fill(a, a + 5, 0);
        fill(b, b + 5, 0);

        int cnt1;
        cin >> cnt1;
        for (int j = 0; j < cnt1; j++) {
            int shape;
            cin >> shape;
            a[shape]++;
        }
        int cnt2;
        cin >> cnt2;
        for (int j = 0; j < cnt2; j++) {
            int shape;
            cin >> shape;
            b[shape]++;
        }
        bool check = false;

        for (int j = 4; j >= 1; j--) {
            if (a[j] > b[j]) {
                check = true;
                cout << "A" << "\n";
                break;
            } else if (a[j] < b[j]) {
                cout << "B" << "\n";
                check = true;
                break;
            }
        }

        if (!check) {
            cout << "D" << "\n";
        }

    }

    return 0;
}