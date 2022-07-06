#include <iostream>
#include <regex>


using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    bool check;
    string str;

    cin >> str;

    //(100~1~|01)~
    regex re("(100+1+|01)+");

    check = regex_match(str, re);


    if (!check) {
        cout << "NOISE";
    }else
        cout << "SUBMARINE";

    return 0;
}