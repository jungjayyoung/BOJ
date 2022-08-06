#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> op;//연산자를 담을 스택


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;


    for (int i = 0; i < s.size(); i++) {

        if(s[i] >= 'A' && s[i] <= 'Z'){

            cout << s[i];
        }else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '('){

            if(op.empty()){
                op.push(s[i]);
                continue;
            }
            if(s[i] == '-' || s[i] == '+'){
                if (op.top() == '*' || op.top() == '/') {

                    while (!op.empty() && op.top() != '(') {
                        cout << op.top();
                        op.pop();
                    }
                }else if(op.top() == '-' || op.top() == '+'){
                    cout << op.top();
                    op.pop();
                }
            }else if(s[i] == '*' || s[i] =='/'){

                while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
                    cout << op.top();
                    op.pop();
                }

            }
            op.push(s[i]);
        } else if (s[i] == ')') {

            while(!op.empty() && op.top() != '('){
                cout << op.top();
                op.pop();
            }
            op.pop();
        }

    }

    while(!op.empty()){
        cout << op.top();
        op.pop();
    }





    return 0;
}