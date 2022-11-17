#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,l;

    cin >> n >>l;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    int s = v[0];
    int cnt = 1;
    int t;
    for (int i = 1; i < v.size(); i++) {

        t = v[i] - s;

        if(t > l - 1) {
            cnt++;
            s = v[i];

        }

    }


    cout << cnt;


    return 0;
}