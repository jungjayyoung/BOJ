#include <iostream>
#include <string>


using namespace std;


int p[14];
int k[14];
int h[14];
int t[14];



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;

    cin >> str;

    int pp = 13;
    int kk = 13;
    int tt = 13;
    int hh = 13;

    for (int i = 0; i < str.size(); i += 3) {
        string tmp = "";
        tmp = tmp + str[i + 1] + str[i + 2];
        int num = stoi(tmp);
        if (str[i] == 'P') {

            if (p[num] == 0) {
                p[num] = 1;
                pp--;
            } else {
                cout << "GRESKA";
                return 0;
            }

        } else if (str[i] == 'K') {
            if (k[num] == 0) {
                k[num] = 1;
                kk--;
            } else {
                cout << "GRESKA";
                return 0;
            }

        } else if (str[i] == 'T') {

            if (t[num] == 0) {
                t[num] = 1;
                tt--;
            } else {
                cout << "GRESKA";
                return 0;
            }
        } else if (str[i] == 'H') {

            if (h[num] == 0) {
                h[num] = 1;
                hh--;
            } else {
                cout << "GRESKA";
                return 0;
            }
        }
    }


    cout << pp << " " << kk << " " << hh << " " << tt;


    return 0;
}