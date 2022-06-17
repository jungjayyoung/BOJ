#include <iostream>
#include <string>


using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    string s;
    string k;

    cin >> str >> k;

    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            s += str[i];
        }
    }



    if (s.find(k) != -1) {
        cout << 1;
    }else
        cout << 0;

    return 0;
}