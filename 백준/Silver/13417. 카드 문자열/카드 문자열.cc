#include <iostream>
#include <string>

using namespace std;

char alp[1001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--) {

        int n;
        string str = "";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> alp[i];
        }

        str += alp[0];

        for (int i = 1; i < n; i++) {
            if (str[0] < alp[i]) {
                str = str + alp[i];
            }else{
                str = alp[i] + str;
            }
        }
        cout << str;
        cout << "\n";


    }


    return 0;
}