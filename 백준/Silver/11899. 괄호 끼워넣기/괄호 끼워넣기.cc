#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;

    cin >> s;

    int cnt = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') {
            if (st.empty()) {
                cnt++;
            }else{
                st.pop();
            }
        } else if (s[i] == '(') {
            st.push('(');
        }
    }

    while (!st.empty()) {
        st.pop();
        cnt++;
    }


    cout << cnt;




    return 0;
}