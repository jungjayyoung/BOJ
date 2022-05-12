#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<char> v;
stack<char> st;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;

    cin >> str;

    for (int i = 0; i < str.size(); i++) {

        if (str[i] == '(') {
            st.push('(');
            continue;
        }

        if(str[i] == ')'){

            while (st.top() != '(') {

                v.push_back(st.top());
                st.pop();
            }
            st.pop();
            // 만약에 다음에 숫자가 있다면
            if(i + 1 <str.size() && str[i + 1] >= '2' && str[i + 1] <= '9'){
                int num = str[i + 1] - '0';
                while (num--) {
                    for (int i = 0; i < v.size(); i++) {
                        st.push(v[i]);
                    }
                }
                v.clear();
                i++;
            }else{ //만약에 다음에 숫자가 없다면
                for (int i = 0; i < v.size(); i++) {
                    st.push(v[i]);
                }
                v.clear();
            }
            continue;
        }

        if(str[i] == 'H' || str[i] == 'C' || str[i] == 'O'){
            st.push(str[i]);
        }

        if (str[i] >= '2' && str[i] <= '9') {
            int cnt = str[i] - '0';

            for (int i = 0; i < cnt - 1; i++) {
                st.push(st.top());
            }

        }

    }


    int sum = 0;

    while(!st.empty()){

        if(st.top() == 'C'){
            sum += 12;
        }else if(st.top() == 'H'){
            sum +=1;

        }else if(st.top() == 'O'){
            sum += 16;
        }

        st.pop();
    }

    cout << sum;
    return 0;
}

