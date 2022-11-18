#include <iostream>

typedef long long ll;
using namespace std;

ll d,k;

ll dpa[31];
ll dpb[31];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> d >> k;

    dpa[1] = 1;
    dpa[2] = 2;
    dpb[1] = 2;
    dpb[2] = 3;

    for (int i = 3; i <= 30; i++) {
        dpa[i] = dpa[i - 1] + dpa[i - 2];
    }

    for (int i = 3; i <= 30; i++) {
        dpb[i] = dpb[i - 1] + dpb[i - 2];
    }

    if (d >= 4) {
        for (int a = 1; a <= 100000; a++) {
            for (int b = a; b <= 100000; b++) {
                ll sum = dpa[d - 3] * a + dpb[d - 3] * b;
                if(sum > k) break;
                if (sum == k) {
                    cout << a << "\n" << b;
                    return 0;
                }
            }

        }
    }else{

        for (int a = 1; a <= 100000; a++) {
            for (int b = a; b <= 100000; b++) {
                ll sum = a + b;
                if(sum > k) break;
                if (sum == k) {
                    cout << a << "\n" << b;
                    return 0;
                }
            }

        }


    }




    return 0;
}