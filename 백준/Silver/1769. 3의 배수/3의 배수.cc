#include <iostream>
#include <string>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string num;

    cin >> num;


    int num_size = num.size();
    int cnt = 0;

    while (num_size > 1) {

        int sum_num = 0;

        for (int i = 0; i < num.size(); i++) {
            sum_num += num[i] - '0';
        }

        num = to_string(sum_num);
        num_size = num.size();
        cnt++;


    }

    cout << cnt << "\n";

    if ((num[0] - '0') % 3 == 0) {
        cout << "YES";
    }else
        cout << "NO";


    return 0;
}