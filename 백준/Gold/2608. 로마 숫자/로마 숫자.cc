#include <iostream>
#include <string>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);



    string r1, r2;
    int num1 = 0, num2 = 0;

    cin >> r1 >> r2;

    // 큰 숫자 왼쪽, 작은 숫자 오른쪽 순서
    // 예외: 4,9,40,90,400,900
    // IV,IX,XL,XC,CD,CM

    for (int i = 0; i < r1.size(); i++) {

        if (i + 1 < r1.size() && r1[i] == 'I' && r1[i + 1] == 'V') {
            num1 += 4;
            i++;
            continue;
        }else if(i + 1 < r1.size() && r1[i] == 'I' && r1[i + 1] == 'X'){
            num1 += 9;
            i++;
            continue;
        }else if(i + 1 < r1.size() && r1[i] == 'X' && r1[i + 1] == 'L') {
            num1 += 40;
            i++;
            continue;
        } else if (i + 1 < r1.size() && r1[i] == 'X' && r1[i + 1] == 'C') {
            num1 += 90;
            i++;
            continue;
        } else if (i + 1 < r1.size() && r1[i] == 'C' && r1[i + 1] == 'D') {
            num1 += 400;
            i++;
            continue;
        } else if (i + 1 < r1.size() && r1[i] == 'C' && r1[i + 1] == 'M') {
            num1 += 900;
            i++;
            continue;
        }
        if (r1[i] == 'I') {
            num1 += 1;
        }
        if (r1[i] == 'V') {
            num1 += 5;
        }
        if (r1[i] == 'X') {
            num1 += 10;
        }
        if (r1[i] == 'L') {
            num1 += 50;
        }if (r1[i] == 'C') {
            num1 += 100;
        }
        if (r1[i] == 'D') {
            num1 += 500;
        }
        if (r1[i] == 'M') {
            num1 += 1000;
        }


    }

    for (int i = 0; i < r2.size(); i++) {

        if (i + 1 < r2.size() && r2[i] == 'I' && r2[i + 1] == 'V') {
            num2 += 4;
            i++;
            continue;
        }else if(i + 1 < r2.size() && r2[i] == 'I' && r2[i + 1] == 'X'){
            num2 += 9;
            i++;
            continue;
        }else if(i + 1 < r2.size() && r2[i] == 'X' && r2[i + 1] == 'L') {
            num2 += 40;
            i++;
            continue;
        } else if (i + 1 < r2.size() && r2[i] == 'X' && r2[i + 1] == 'C') {
            num2 += 90;
            i++;
            continue;
        } else if (i + 1 < r2.size() && r2[i] == 'C' && r2[i + 1] == 'D') {
            num2 += 400;
            i++;
            continue;
        } else if (i + 1 < r2.size() && r2[i] == 'C' && r2[i + 1] == 'M') {
            num2 += 900;
            i++;
            continue;
        }
        if (r2[i] == 'I') {
            num2 += 1;
        }
        if (r2[i] == 'V') {
            num2 += 5;
        }
        if (r2[i] == 'X') {
            num2 += 10;
        }
        if (r2[i] == 'L') {
            num2 += 50;
        }if (r2[i] == 'C') {
            num2 += 100;
        }
        if (r2[i] == 'D') {
            num2 += 500;
        }
        if (r2[i] == 'M') {
            num2 += 1000;
        }
    }

    int sum = num1 + num2;

    cout << sum << "\n";

    int a = sum / 1000;
    int b = (sum % 1000) / 100;
    int c = (sum % 100) / 10;
    int d = sum % 10;

    if (a != 0) {
        if (a == 1) {
            cout << 'M';
        } else if (a == 2) {
            cout << "MM";
        } else if (a == 3) {
            cout << "MMM";
        }
    }

    if (b != 0) {
        if (b == 1) {
            cout << 'C';
        } else if (b == 2) {
            cout << "CC";
        } else if (b == 3) {
            cout << "CCC";
        } else if (b == 4) {
            cout << "CD";
        } else if (b == 5) {
            cout << 'D';
        } else if (b == 6) {
            cout << "DC";
        } else if (b == 7) {
            cout << "DCC";
        }else if (b == 8) {
            cout << "DCCC";
        } else if (b == 9) {
            cout << "CM";
        }
    }
    if (c != 0) {
        if (c == 1) {
            cout << 'X';
        } else if (c == 2) {
            cout << "XX";
        } else if (c == 3) {
            cout << "XXX";
        } else if (c == 4) {
            cout << "XL";
        } else if (c == 5) {
            cout << 'L';
        } else if (c == 6) {
            cout << "LX";
        } else if (c == 7) {
            cout << "LXX";
        }else if (c == 8) {
            cout << "LXXX";
        } else if (c == 9) {
            cout << "XC";
        }
    }
    if (d != 0) {
        if (d == 1) {
            cout << 'I';
        } else if (d == 2) {
            cout << "II";
        } else if (d == 3) {
            cout << "III";
        } else if (d == 4) {
            cout << "IV";
        } else if (d == 5) {
            cout << 'V';
        } else if (d == 6) {
            cout << "VI";
        } else if (d == 7) {
            cout << "VII";
        }else if (d == 8) {
            cout << "VIII";
        } else if (d == 9) {
            cout << "IX";
        }
    }

    return 0;
}

