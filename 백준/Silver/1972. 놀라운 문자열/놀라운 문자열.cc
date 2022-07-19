#include <iostream>
#include <string>
#include <set>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {

        string str;


        cin >> str;
        if(str == "*"){
            break;
        }
        int bf_cnt = 0;
        int at_cnt = 0;

        if (str.size() == 1) {
            cout << str << " is surprising." << "\n";
            continue;
        }

        bool check = false;
        for (int i = 1; i <= str.size() - 1; i++) {
            set<string> s;
            for (int j = 0; j + i < str.size(); j++) {
                string tmp;
                tmp = tmp + str[j] + str[j + i];
                bf_cnt = s.size();
                s.insert(tmp);
                at_cnt = s.size();
                if (bf_cnt == at_cnt) {
                    check = true;
                }
            }
            if(check)
                break;
        }

        if (check) {
            cout << str << " is NOT surprising." << "\n";
        }else
            cout << str << " is surprising." << "\n";
    }


    return 0;
}