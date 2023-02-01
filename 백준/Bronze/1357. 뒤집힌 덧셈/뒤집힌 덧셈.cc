#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string x, y;

    cin >> x >> y;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    int sum = stoi(x) + stoi(y);

    string tmp = to_string(sum);

    reverse(tmp.begin(), tmp.end());

    cout << stoi(tmp);

    return 0;
}