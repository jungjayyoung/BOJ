#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int l, t;
int n;
vector<int> ans;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // l: 줄의 길이, t: t초가 지난 후 개미의 위치를 구해야 한다.
    cin >> l >> t;

    // t: 처음 위치에 같은 방향으로 돌아오는 주기
    t = t % (l * 2);

    // n: 개미의 수
    cin >> n;

    //L : 왼쪽, D: 오른쪽
    for (int i = 1; i <= n; i++) {
        int cur;
        char dir;
        cin >> cur >> dir;

        if (dir == 'D') {
            if (cur + t <= l) {
                ans.push_back(cur + t);
            } else if (t - (l - cur) <= l) {
                ans.push_back(l - (t - (l - cur)));
            }else{
                ans.push_back(t - ((l - cur) + l));
            }

        } else if (dir == 'L') {

            if (cur - t >= 0) {
                ans.push_back(cur - t);
            } else if (t - cur <= l) {
                ans.push_back(t - cur);
            }else{
                ans.push_back(l - (t - (cur + l)));
            }


        }



    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }


    return 0;
}