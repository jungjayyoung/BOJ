#include <iostream>
#include <cmath>

using namespace std;

int arr[4];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }

    cout << abs((arr[0] + arr[3]) - (arr[1] + arr[2]));

    return 0;
}