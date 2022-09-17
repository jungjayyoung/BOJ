#include <iostream>
#include <vector>

using namespace std;

//1. vector STL에 있는 lower_bound, upper_bound는 찾으려는 키값보다 같거나 큰 숫자가
// 배열 몇 번째에 처음 등장하는지 찾을 때 사용할 수 있다.

int arr[1000001];
vector<int> v;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 1. 벡터를 생성하고 최솟값을 집어 넣는다.
    v.push_back(-1);

    int cnt = 0;

    for (int i = 0; i < n; i++) {

        //2. arr[i]와 벡터의 끝값 back()을 비교하여 arr[i]가 더 크다면 push_back해주고 길이를 증가시킨다.
        if (arr[i] > v.back()) {
            v.push_back(arr[i]);
            cnt++;
        }else{
            //3. back이 더 크다면 lower_bound를 찾고 그 위치에 arr[i]를 집어 넣는다

            vector<int>::iterator low = lower_bound(v.begin(), v.end(), arr[i]);
            *low = arr[i];
        }
    }

    cout << cnt;

    return 0;
}