#include <iostream>
#include <algorithm>

using namespace std;


int n,d,k,c; //접시 수, 가짓수, 연속 수, 쿠폰번호

int plate[33001];
int sushi[3001];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> d >> k >> c;

    for (int i = 0; i < n; i++) {
        cin >> plate[i];
    }

    for (int i = n; i < n + k; i++) {
        plate[i] = plate[i - n];
    }


    int start = 0;
    int end = 1;

    int ans;
    int cnt = 1;
    sushi[plate[0]]++;
    sushi[plate[1]]++;
    if (plate[0] != plate[1]) {
        ans = 2;
    }else
        ans = 1;


    // 쿠폰에 있는 초밥이 없으면 ans를 1 증가시킨다.
    if (plate[0] != c && plate[1] != c) {
        ans++;
    }

    while (start != n - 1) {


        if(end - start + 1 < k ){
            end++;
            sushi[plate[end]]++;
            if (sushi[plate[end]] == 1) {

                if (plate[end] != c) {
                    ans++;
                }
            }


        } else if (end - start + 1 >= k) {

            sushi[plate[start]]--;
            if (sushi[plate[start]] == 0) {
                if (plate[start] != c) {
                    ans--;
                }
            }
            start++;
        }

        cnt = max(cnt, ans);

    }


    cout << cnt;

    return 0;
}