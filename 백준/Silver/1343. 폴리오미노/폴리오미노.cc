#include <iostream>
#include <string>
#include <stack>
using namespace std;


stack<char> st;
stack<char> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string board;

    cin >> board;


    for (int i = 0; i < board.size(); i++) {
        st.push(board[i]);
    }

    int xcnt = 0;

    while (!st.empty()) {
        if (st.top() == 'X') {
            xcnt++;
            st.pop();
        } else if (st.top() == '.') {

            while (xcnt > 0) {

                if (xcnt % 4 == 0) {
                    ans.push('A');
                    ans.push('A');
                    ans.push('A');
                    ans.push('A');
                    xcnt = xcnt - 4;

                } else if (xcnt % 2 == 0) {
                    ans.push('B');
                    ans.push('B');
                    xcnt = xcnt - 2;

                }else{
                    cout << -1;
                    return 0;
                }

            }
            ans.push('.');
            st.pop();
        }
    }

    while (xcnt > 0) {

        if (xcnt % 4 == 0) {
            ans.push('A');
            ans.push('A');
            ans.push('A');
            ans.push('A');
            xcnt = xcnt - 4;
        } else if (xcnt % 2 == 0) {
            ans.push('B');
            ans.push('B');
            xcnt = xcnt - 2;
        }else{
            cout << -1;
            return 0;
        }

    }

    string s;
    while (!ans.empty()) {
        s = s + ans.top();
        ans.pop();
    }

    cout << s;



    return 0;
}