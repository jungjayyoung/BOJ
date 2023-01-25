#include <iostream>
#include <set>

using namespace std;


set<int> st;
int n, m;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        st.insert(num);
    }
    int dup_cnt = 0;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        if (st.find(num) != st.end()) {
            dup_cnt++;
        }
    }

    cout << (n - dup_cnt) + (m - dup_cnt);


    return 0;
}