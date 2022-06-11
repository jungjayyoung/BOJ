#include <iostream>
#include <string>

using namespace std;

bool alp[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (1) {

        string str;
        cin >> str;

        if (str == "end") {
            break;
        }
        bool check = false;

        int vowel_cnt = 0;
        int conso_cnt = 0;
        bool is_vowel = false;

        for (int i = 0; i < str.size(); i++) {

            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
                is_vowel = true;
                conso_cnt = 0;
                vowel_cnt++;

                if (vowel_cnt >= 3) {
                    check = true;
                    break;

                }

            }else{

                    vowel_cnt = 0;
                    conso_cnt++;

                    if (conso_cnt >= 3) {
                        check = true;
                        break;
                    }
                }
            if (i >= 1) {
                if (str[i - 1] == str[i]) {

                    if(str[i] != 'e' && str[i] != 'o') {
                        check  =true;
                    }
                }
            }

        }

        if (!check && is_vowel) {
            cout << "<" << str << ">" << " is acceptable." << "\n";
        }else{
            cout << "<" << str << ">" << " is not acceptable." << "\n";
        }

    }


    return 0;
}