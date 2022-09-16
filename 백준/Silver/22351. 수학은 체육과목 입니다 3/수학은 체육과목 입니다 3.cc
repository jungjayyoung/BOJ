#include <iostream>
#include <string>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;

    cin >> s;

    int first_num;

    // 첫번째 숫자가 사이즈가 1인 경우
    for (int i = 1; i <= 3; i++) {
        first_num = stoi(s.substr(0, i));
        int size = i;
        int num = first_num;
        string tmp = s.substr(0, i);
        string tmp2 = tmp;
        while (size < s.size()) {
            tmp = to_string(++num);
            tmp2 += tmp;
            size += tmp.size();
        }

        if (size == s.size() && tmp2 == s) {
            cout << first_num << " " << tmp;
            return 0;
        }

    }


    cout << s << " " << s;


    return 0;
}