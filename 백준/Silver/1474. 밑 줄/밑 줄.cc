#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int n, m;
vector<string> v;
vector<int> line_cnt;
string ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int len = 0;


    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        len += str.length();
        ans += str;
        v.push_back(str);
    }

    //len : 단어만 합했을 때의 길이

    // line_cnt : 기본적으로 주어지는 '_'의 개수
    int line_cnt = (m - len) / (n - 1);
    // r: 추가해야 되는 r의 개수
    int r = (m - len) % (n - 1);

    ans = v[0];
    for (int i = 1; i < n; i++) {

        // 첫번째 단어 이후 소문자일 경우 '_'을 추가해준다.
        if (v[i][0] >= 'a' && v[i][0] <= 'z' && r > 0) {
            r--;
            for (int i = 0; i < line_cnt + 1; i++) {
                ans += '_';
            }
            ans += v[i];
        // 현재 인덱스에서 남은 추가개수가 n일 경우
        } else if (i + r == n) {
            r--;
            for (int i = 0; i < line_cnt + 1; i++) {
                ans += '_';
            }
            ans += v[i];
        } else {
            for (int i = 0; i < line_cnt; i++) {
                ans += '_';
            }
            ans += v[i];
        }
    }

    cout << ans;

    return 0;
}