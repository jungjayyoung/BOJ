#include <iostream>


using namespace std;

string dp1[101]; // 큰 수
string dp2[101]; // 작은 수

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    dp1[2] = "1";
    dp1[3] = "7";
    dp1[4] = "11";
    dp1[5] = "71";



    // 가장 큰 수의 규칙
    for (int i = 4; i <= 100; i++) {
        if (i % 2 == 0) {
            dp1[i] = dp1[i - 2] + "1";
        }else{
            dp1[i] = dp1[i - 1];
            dp1[i][0] = '7';
        }
    }

    // 가장 작은 수의 규칙
    dp2[2] = "1";
    dp2[3] = "7";
    dp2[4] = "4";
    dp2[5] = "2";
    dp2[6] = "6"; // 0 이 있다
    dp2[7] = "8";
    dp2[8] = "10";
    dp2[9] = "18";
    dp2[10] = "22";
    dp2[11] = "20";
    dp2[12] = "28";
    dp2[13] = "68";
    dp2[14] = "88";
    dp2[15] = "108";
    dp2[16] = "188";
    dp2[17] = "200";
    dp2[18] = "208";
    dp2[19] = "288";
    dp2[20] = "688";

    for (int i = 21; i <= 100; i++) {
        dp2[i] = dp2[i - 7] + "8";
    }

    for (int i = 0; i < t; i++) {
        int num;
        cin >> num;

        cout << dp2[num] << " " << dp1[num] << "\n";
    }





    return 0;
}