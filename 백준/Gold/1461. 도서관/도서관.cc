#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    v.push_back(0);
    sort(v.begin(), v.end());
    int zero_pos;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) {
            zero_pos = i;
            break;
        }

    }

    int sum = 0;

    for (int i = 0; i < zero_pos; i += m) {
        sum += abs(v[i] * 2);
    }

    for (int i = n; i > zero_pos; i -= m) {
        sum += v[i] * 2;
    }

    sum -= max(abs(v[0]), abs(v[n]));



    cout << sum;



}