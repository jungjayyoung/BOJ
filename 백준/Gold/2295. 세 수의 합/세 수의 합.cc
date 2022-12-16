#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> v;
map<int,bool> m;

//맵을 사용한 풀이 방법
// 1. map의 키값으로 두 수의 합을 저장하고 값을 true로 넣어준다.
// 2. 이중 for문을 돌려서 큰 수 - 작은 수를 키 값으로 가지는 map이 있는지 find를 통해 찾는다
// 3. map은 키 값이 존재하지 않으면 end()를 리턴한다.
// 4. 키 값이 존재한다는 뜻은 두 수의 합이 존재한다는 뜻이다.
// 즉 세 수를 더한 큰 수가 존재한다는 뜻이다. n^2 으로 문제가 풀린다.

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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m.insert({v[i] + v[j], true});
        }
    }
    int maxx = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (m.find(v[j] - v[i]) != m.end()) {
                maxx = max(maxx, v[j]);
            }

        }
    }

    cout << maxx;

    return 0;
}