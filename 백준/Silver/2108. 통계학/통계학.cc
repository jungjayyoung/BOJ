#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


int num[500001];
pair<int,int> cnt[8001];
vector<int> v;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    double sum = 0;
    double avg;


    cin >> n;

    for (int i = 0; i <= 8000; i++) {
        cnt[i].second = i - 4000;
    }


    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        sum += (double)num[i];
        cnt[num[i] + 4000].first++;
    }

    avg = sum / n;

    //1. 산술 평균
    if (round(avg) == 0) {
        cout << 0 << "\n";
    }else{
        cout << round(avg) << "\n";
    }



    // 2. 중앙값
    sort(num + 1, num + n + 1);
    cout << num[n / 2 + 1] << "\n";



    //3. 최빈값
    sort(cnt, cnt + 8001, greater<>());
    if (cnt[0].first != cnt[1].first) {
        cout << cnt[0].second << "\n";
    }else{
        //만약에 동일한 최빈값이 여러개가 존재한다면 가장 작은 숫자에서 두번째 출력
        v.push_back(cnt[0].second);
        for (int i = 1; i <= 8000; i++) {
            if (cnt[0].first == cnt[i].first) {
                v.push_back(cnt[i].second);
            }else
                break;
        }

        sort(v.begin(), v.end());
        cout << v[1] << "\n";
    }

    //4. 범위
    cout << num[n] - num[1] << "\n";

    return 0;
}