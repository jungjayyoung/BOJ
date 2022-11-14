#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int arr[100001];
int visited[100001];
int n;
typedef long long ll;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int i = 0;
    int j = 0;
    ll cnt = 0;

    while (j < n) {

        visited[arr[j]]++;
        if (visited[arr[j]] >= 2) {

            while (visited[arr[j]] == 2) {
                visited[arr[i]]--;
                i++;
            }
            cnt += j - i + 1;
        }else{
            cnt += j - i + 1;
        }

        j++;

    }



    cout << cnt;


    return 0;
}