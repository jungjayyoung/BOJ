#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> v;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    v.push_back(2000000000);
    v.push_back(2000000000);
    v.push_back(2000000000);
    v.push_back(2000000000);
    v.push_back(2000000000);
    v.push_back(2000000000);

    sort(v.begin(), v.end());

    int ans = 1;

    for (int i = 0; i < n; i++) {
        int cnt = 1;

        for (int j = i + 1; j < i + 5; j++) {
            //cout << v[j] << " ";

            if (v[j] - v[i] < 5 && v[j] - v[i] > 0) {
                cnt++;
            }

        }
        ans = max(ans, cnt);

    }


    cout << 5 - ans;






    return 0;
}