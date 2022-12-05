#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[10001];

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    sort(arr, arr + n);

    for (int i = 1; i < n; i++) {
        v.push_back(arr[i] - arr[i - 1]);
    }

    sort(v.begin(), v.end());

    int sum = 0;
    for (int i = 0; i < n - k; i++) {
        sum += v[i];
    }

    cout << sum;

    return 0;
}