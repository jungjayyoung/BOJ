#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

string s,e,q;
int st_h, st_m, e_h, e_m, q_h, q_m;

set<string> sss;
set<string> eee;
vector<string> ss;
vector<string> ee;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> e >> q;

    st_h = stoi(s.substr(0, 2));
    st_m = stoi(s.substr(3, 2));
    e_h = stoi(e.substr(0, 2));
    e_m = stoi(e.substr(3, 2));
    q_h = stoi(q.substr(0, 2));
    q_m = stoi(q.substr(3, 2));

    cin.ignore();

    while (1) {

        string chat;
        int hh, mm;
        string nickname;

        getline(cin, chat);

        if (cin.eof()) {
            break;
        }

        hh = stoi(chat.substr(0, 2));
        mm = stoi(chat.substr(3, 2));
        nickname = chat.substr(6);

        if ((hh == st_h && mm <= st_m) || hh < st_h) {
            sss.insert(nickname);
        }

        if ((hh == e_h && mm >= e_m) || hh > e_h) {

            if ((hh == q_h && mm <= q_m) || hh < q_h) {
                eee.insert(nickname);
            }

        }

    }

    for (auto &i: sss) {
        ss.push_back(i);
    }


    for (auto &i: eee) {
        ee.push_back(i);
    }

    sort(ss.begin(), ss.end());
    sort(ee.begin(), ee.end());

    int a = 0;
    int b = 0;
    int ans = 0;

    while (a < ss.size() && b < ee.size()) {

        if (ss[a] == ee[b]) {
            a++;
            b++;
            ans++;
        } else if (ss[a] < ee[b]) {
            a++;
        } else if (ss[a] > ee[b]) {
            b++;
        }

    }


    cout << ans;
    return 0;
}