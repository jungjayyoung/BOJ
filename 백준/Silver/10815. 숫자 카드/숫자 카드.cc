#include <iostream>
#include <set>

using namespace std;


int n, m;
set<int> st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        st.insert(num);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        if (st.find(num) != st.end()) {
            cout << 1;
        }else
            cout << 0;
        cout << " ";
    }

    return 0;
}