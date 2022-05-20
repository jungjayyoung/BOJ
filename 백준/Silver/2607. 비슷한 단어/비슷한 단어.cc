#include <iostream>
#include <string>

using namespace std;

int str_alp_cnt[28];
int tmp_alp_cnt[28];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string str;

    cin >> n;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        str_alp_cnt[str[i] - 'A']++;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        string tmp;

        cin >> tmp;


        copy(str_alp_cnt, str_alp_cnt + 26, tmp_alp_cnt);

        bool check = false;
        int same_cnt = 0;


        for (int j = 0; j < tmp.size(); j++) {
            if (tmp_alp_cnt[tmp[j] - 'A'] > 0) {
                same_cnt++;
                tmp_alp_cnt[tmp[j] - 'A']--;
            }
        }


        if (tmp.size() == str.size()) {

            if (same_cnt == str.size() || same_cnt + 1 == str.size()) {
                check = true;
            }
        }

        //비교 문자열이 1 작은 경우
        if (tmp.size() + 1 == str.size()) {
            if (same_cnt + 1 == str.size()) {
                check = true;
            }
        }

        // 비교 문자열이 1 큰 경우
        if (tmp.size() - 1 == str.size()) {
            if (same_cnt == str.size()) {
                check = true;
            }
        }


        if(check){
            ans++;
        }

    }


    cout << ans;

    return 0;
}