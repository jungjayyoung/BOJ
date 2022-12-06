#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[51];
vector<int> a1;
vector<int> a2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 1. 음수끼리는 무조건 묶는다.
    // 2. 0 이 있으면 건너뛰거나, 짝이 없는 음수와 묶을 수 있으면 묶는다.
    // 3. 0 이 없을 경우 짝이 없는 음수는 그냥 더한다.
    // 3. 양수는 큰 수 끼리 무조건 묶는다.
    // 4. 짝이 없는 양수는 그냥 더한다.

    sort(arr, arr + n);

    bool zero_check = false;
    for (int i = 0; i < n; i++) {

        if (arr[i] < 0) {
            a1.push_back(arr[i]);
        } else if (arr[i] > 0) {
            a2.push_back(arr[i]);
        }else
            zero_check = true;
    }

    int sum = 0;

    //1. 음수끼리 묶기
    if (a1.size() > 1) {

        for (int i = 0; i < a1.size(); i += 2) {
            if (i + 1 >= a1.size()) break;
            sum += (a1[i] * a1[i + 1]);
        }

        if (a1.size() % 2 == 1 && !zero_check) {
            sum += a1.back();
        }

    } else if (a1.size() == 1 && !zero_check) {
        sum += a1.front();
    }

    //cout << sum << "\n";

    //2. 양수끼리 묶기
    if (a2.size() > 1) {

        // 뒤에서부터 묶는다.
        for (int i = a2.size() - 1; i >= 0; i -= 2) {
            if (i - 1 < 0) {
                break;
            }
            if (a2[i - 1] == 1) {
                sum += a2[i] + a2[i - 1];
            }else
                sum += (a2[i] * a2[i - 1]);
        }

        if (a2.size() % 2 == 1) {
            sum += a2.front();
        }

    } else if (a2.size() == 1) {
        sum += a2.front();
    }

    cout << sum;


}