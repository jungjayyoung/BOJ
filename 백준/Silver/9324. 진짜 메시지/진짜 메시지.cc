#include <iostream>
#include <string>

using namespace std;


int alp[27];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--) {
        fill(alp, alp + 26, 0);
        string str;

        cin >> str;
        bool check = false;

        for (int i = 0; i < str.size() - 1; i++) {

            alp[str[i] - 'A']++;

            if (i >= 2) {
                if(alp[str[i] - 'A'] != 0 && alp[str[i] - 'A'] % 3 == 0){
                    if (str[i + 1] == str[i]) {
                        i++;
                    }else{
                        check =true;
                        break;
                    }
                }

            }

        }
        //마지막 문자 체크
        alp[str[str.size()-1] - 'A']++;
        if (alp[str[str.size() - 1] - 'A'] % 3 == 0) {
            check = true;
        }

        if (!check) {
            cout << "OK";
        }else{
            cout << "FAKE";}

        cout << "\n";
    }



    return 0;
}