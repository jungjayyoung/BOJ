#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[200000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    memset(arr, -1, sizeof(arr));
    int n;
    int result = -1;
    cin >>n;


    for (int i = 0; i < (n *(n+1))/2; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++) {
        for(int j = (i*(i+1))/2; j<= ((i*(i+1))/2) + i; j++ ){

            if(j == (i*(i+1))/2){
                arr[j] += arr[j-i];
            }else if(j == ((i*(i+1))/2) + i){
                arr[j] += arr[j -(i+1)];
            }else
                arr[j] += max(arr[j - i], arr[j - (i + 1)]);
            result = max(result, arr[j]);
        }

    }


    if(n==1)
        cout <<arr[0];
    else
        cout << result;


    return 0;
}