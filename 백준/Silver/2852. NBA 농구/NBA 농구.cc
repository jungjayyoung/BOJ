#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int,int>> ss; // first: 팀, second: 초


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num, mm, sss, total;
        string s;
        cin >> num >> s;

        mm = stoi(s.substr(0, 2));
        sss = stoi(s.substr(3, 2));
        total = mm * 60 + sss;
        ss.push_back({num, total});
    }


    int cnt = 0;
    int one_score = 0;
    int two_score = 0;
    int total_time = 48 * 60;
    int idx = 0;
    int one_total = 0;
    int two_total = 0;

    while (cnt < total_time) {



        if (idx != ss.size() && cnt == ss[idx].second) {

            if (ss[idx].first == 1) {
                one_score++;
            }else{
                two_score++;
            }

            idx++;

        }

        if (one_score > two_score) {
            one_total++;
        } else if (one_score < two_score) {
            two_total++;
        }

        cnt++;
    }

    int one_m = one_total / 60;
    int one_s = one_total % 60;
    int two_m = two_total / 60;
    int two_s = two_total % 60;


    if (one_m < 10) {
        cout << '0';
    }

    cout << one_total / 60 << ':';
    if (one_s < 10) {
        cout << '0';
    }
    cout << one_total % 60 << "\n";

    if (two_m < 10) {
        cout << '0';
    }
    cout << two_total / 60 << ':';

    if (two_s < 10) {
        cout << '0';
    }
    cout << two_total % 60 << "\n";

    return 0;
}