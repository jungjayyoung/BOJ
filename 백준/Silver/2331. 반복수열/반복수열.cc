#include <iostream>
#include <set>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

string a;
int p;


set<int> st;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> a >> p;

    string start = a;
    st.insert(stoi(a));
    ans.push_back(stoi(a));

    int the_num;
    while (1) {

        int num = 0;

        for (int i = 0; i < start.size(); i++) {
            num = num + pow(start[i] - '0', p);
        }

        if (st.find(num) == st.end()) {
            st.insert(num);
            start = to_string(num);
            ans.push_back(num);
        }else{
            the_num = num;
            break;
        }

    }
    int cnt = 0;

    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] != the_num) {
            cnt++;
        }else
            break;
    }


    cout << cnt;
    return 0;
}