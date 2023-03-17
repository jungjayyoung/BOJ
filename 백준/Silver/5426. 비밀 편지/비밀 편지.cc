#include <iostream>
#include <string>

using namespace std;

int n;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int t = 0; t < n; t++) {
        string str;
        cin >> str;

        int num = 0;

        for (int i = 1; i <= str.size(); i++) {
            if (i * i == str.size()) {
                num = i;
                break;
            }
        }


        for (int j = num - 1; j >= 0; j--) {
            for (int i = 0; i < num; i++) {
                //cout << i * num + j << " ";
                cout << str[i * num + j];
            }
        }

        cout << "\n";


    }


    return 0;
}