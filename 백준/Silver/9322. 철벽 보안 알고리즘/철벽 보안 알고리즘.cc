#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<string> key1;
vector<string> key2;
vector<string> encrypted;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            key1.push_back(s);
        }
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            key2.push_back(s);
        }
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            encrypted.push_back(s);
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (key1[i] == key2[j]) {
                    cout << encrypted[j] << " ";
                    break;
                }

            }

        }
        cout << "\n";


        key1.clear();
        key2.clear();
        encrypted.clear();
    }



    return 0;
}