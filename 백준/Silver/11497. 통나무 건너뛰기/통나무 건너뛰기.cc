#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

vector<int> v;
deque<int> dq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        dq.clear();
        v.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end(), greater<>());

        int ans = -1;
        int cnt = 0;
        bool checkl = false;
        bool checkr = false;

        for (int i = 0; i < v.size(); i++) {
            if (dq.empty()) {
                dq.push_back(v[i]);
                continue;
            }
            if (cnt == 2) {
                cnt = 0;
                checkl = false;
                checkr = false;
            }

            if (cnt == 0) {
                int r = abs(dq.front() - v[i]);
                int l = abs(dq.back() - v[i]);

                if (r <= l) {
                    dq.push_back(v[i]);
                    ans = max(ans, l);
                    checkl = true;
                }else{
                    dq.push_front(v[i]);
                    ans = max(ans, r);
                    checkr = true;
                }
            } else {

                if (checkr) {
                    ans = max(ans, abs(dq.back() - v[i]));
                    dq.push_back(v[i]);

                }

                if (checkl) {
                    ans = max(ans, abs(dq.front() - v[i]));
                    dq.push_front(v[i]);
                }

            }


            cnt++;

        }

        

        cout << ans << "\n";


    }
    return 0;
}