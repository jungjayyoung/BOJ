#include <iostream>


using namespace std;

int year[10000];

// 윤년
int m1[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// 평년
int m2[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    for (int i = 1; i < 10000; i++) {

        if (i % 4 == 0) {
            year[i] = 1;
        }

        if (i % 100 == 0) {
            year[i] = 0;
        }

        if (i % 400 == 0) {
            year[i] = 1;
        }
    }

    int today = 0;
    int dday = 0;

    int a, b, c, a2, b2, c2;

    cin >> a >> b >> c;

    if (year[a] == 1) {
        for (int i = 1; i < b; i++) {
            today += m1[i];
        }
    } else {
        for (int i = 1; i < b; i++) {
            today += m2[i];
        }
    }

    today += c;

    for (int i = 2; i < a; i++) {
        if (year[i] == 1) {
            today += 366;
        }else
            today += 365;
    }

    cin >> a2 >> b2 >> c2;

    if (year[a2] == 1) {
        for (int i = 1; i < b2; i++) {
            dday += m1[i];
        }
    } else {
        for (int i = 1; i < b2; i++) {
            dday += m2[i];
        }
    }

    dday += c2;

    for (int i = 2; i < a2; i++) {
        if (year[i] == 1) {
            dday += 366;
        }else
            dday += 365;
    }

    if (a2 -a > 1000) {
        cout << "gg";
    } else if (a2 - a == 1000) {
        if (b2 - b > 0 || (b2 - b == 0 && c2 - c >= 0)) {
            cout << "gg";
        }else
            cout << "D-" << dday - today;
    } else {
        cout << "D-" << dday - today;
    }



    return 0;
}