#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

int n;

ll liquid[100001];
ll sum = 0;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 1. 두 종류의 산성 용액만으로 0에 가깝게 만드는 법
    // 2. 두 종류의 알칼리성 용액만으로 0 에 가깝게 만드는 법
    // 3. 알칼리성 용액 한가지와 산성 용액 한가지로 0에 가깝게 만드는 법

    cin >> n;


    for (int i = 0; i < n; i++) {
        cin >> liquid[i];
    }

    sort(liquid, liquid + n);



    // 전부 알칼리일 경우

    if (liquid[n - 1] <= 0) {
        sum = liquid[n - 1] + liquid[n - 2];
        cout << liquid[n - 2] << " " << liquid[n - 1];
        return 0;
    }

    // 전부 산성인 경우
    if (liquid[0] >= 0) {
        sum = liquid[0] + liquid[1];
        cout << liquid[0] << " " << liquid[1];
        return 0;
    }



    int i = 0;
    int j = n - 1;
    sum = 9876543210;

    ll ans1 = liquid[0];
    ll ans2 = liquid[n - 1];

    while (i < j) {

        if (i >= j) {
            break;
        }

        ll a = liquid[i];
        ll b = liquid[j];


        // a가 양수이고 b가 음수일때
        if (a <= 0 && b >= 0) {

            if (abs(a + b) < sum) {
                sum = abs(a + b);
                ans1 = a;
                ans2 = b;
            }

            // 절댓값이 큰 쪽이 움직여야 한다.
            if (abs(a) != abs(b)) {

                if (abs(a) > abs(b)) {
                    i++;
                }else{
                    j--;
                }
            }else{
                cout << ans1 << " " << ans2;
                return 0;
            }

        }

        // a가 양수 b도 양수
        if (a > 0 && b > 0) {

            if (a + b < sum) {
                sum = a + b;
                ans1 = a;
                ans2 = b;
            }

            j--;
        }

        //a가 음수 b도 음수
        if (a < 0 && b < 0) {
            if (abs(a + b) < sum) {
                sum = abs(a + b);
                ans1 = a;
                ans2 = b;
            }

            i++;
        }

    }

    cout << ans1 << " " << ans2;

    return 0;
}