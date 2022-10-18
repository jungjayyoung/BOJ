#include <iostream>
#include <algorithm>
using namespace std;

int arr[2250001];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n * n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + (n * n));

    cout << arr[n * n - n];



    return 0;
}