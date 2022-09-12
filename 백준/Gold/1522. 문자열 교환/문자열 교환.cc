#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;

    cin >> str;

    int total_b = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'b') {
            total_b++;
        }
    }

    int b = 0;
    int b_size = 0;

    for (int i = 0; i < total_b; i++) {
        if (str[i] == 'b') {
            b++;
        }
        str += str[i];
    }

    b_size = max(b_size, b);

    for (int i = total_b; i < str.size(); i++) {
        if (str[i - total_b] == 'b') {
            b--;
        }
        if (str[i] == 'b') {
            b++;
        }
        b_size = max(b_size, b);
    }

    cout <<total_b - b_size;

    return 0;
}
