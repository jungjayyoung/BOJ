#include <iostream>
#include <string>

using namespace std;

string a;
string str[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;

    cin >> a;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        str[i] = str[i] + str[i];
        if (str[i].find(a) != string::npos) {
            cnt++;
        }
    }


    cout << cnt;


    return 0;
}