#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
typedef long long ll;


stack<int> st;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int m;

    cin >> m;

    int sum = 0;
    for (int i = m; i >= 1; i--) {
        int num;
        cin >> num;

        sum += pow(a, i - 1) * num;
    }

    while (sum > 0) {

        st.push(sum % b);
        sum /= b;
    }

    
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}