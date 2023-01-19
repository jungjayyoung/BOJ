#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll ans = 0;

    while (1) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<int> v;

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            v.push_back(num);
        }
        v.push_back(-1);

        stack<ll> st;
        st.push(-1);
        ans = 0;

        for (int i = 0; i < v.size(); i++) {

            while (st.size() > 1 && v[i] <v[st.top()]) {
                ll rec_h = st.top();
                st.pop();
                ll left = st.top();
                ans = max(ans, (i - left-1) * v[rec_h]);
            }
            st.push(i);

        }

        cout << ans << "\n";

    }



    return 0;
}