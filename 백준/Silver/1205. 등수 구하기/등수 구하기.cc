#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int n, tae, p;
stack<int> st;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> tae >> p;



    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        st.push(num);
        //v.push_back(num);
    }

    while (!st.empty() && st.size() > p) {
        st.pop();
    }

    while (!st.empty() && st.top() < tae) {
        st.pop();
    }

    if (!st.empty() && st.size() < p) {
        st.push(tae);
        while (!st.empty() && st.top() == tae) {
            st.pop();
        }
        cout << st.size() + 1;
    }else if(st.empty()){
        cout << 1;
    } else {
        cout << -1;
    }

    return 0;
}