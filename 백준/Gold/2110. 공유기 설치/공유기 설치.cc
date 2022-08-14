#include <iostream>
#include <algorithm>

using namespace std;


int arr[200001];
int n, c;

bool check(int dist){

    int pre = arr[0];
    int cnt = 1; // 처음집과 마지막 집 사이의 거리를 생각하면 적어도 1개는 존재한다.

    for (int i = 1; i < n; i++) {

        if(arr[i] - pre >= dist){
            cnt++;
            pre = arr[i];
        }

    }


    if(cnt >= c) {
        return true;
    }else{
        return false;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);



    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);


    int min_distance = 1;
    int max_distance = arr[n - 1] - arr[0];
    int mid;
    int result = 0;

    while (min_distance <= max_distance) {


        mid = (max_distance + min_distance) / 2;


        if(check(mid)) {

            result = max(result, mid);
            min_distance = mid + 1;


        }else{
            max_distance = mid - 1;
        }

    }


    cout << result;

    return 0;
}
