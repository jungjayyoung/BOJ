#include <iostream>
#include <string>
#include <deque>
using namespace std;

string str;
deque<char> d;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    cin >> str;


    for (int i = 0; i < str.size(); i++) {
        if (!d.empty() && d.back() < str[i] && k > 0) {

            while (!d.empty() && k > 0 && d.back() <str[i]) {
                d.pop_back();
                k--;
            }
            d.push_back(str[i]);
        } else
            d.push_back(str[i]);

    }


    while (k > 0) {
        d.pop_back();
        k--;
    }

    while(!d.empty()){
        cout<< d.front();
        d.pop_front();
    }
    return 0;
}

