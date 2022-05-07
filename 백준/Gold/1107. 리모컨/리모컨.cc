#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int error_num;
vector<char> broken_number;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;

    //1. 100 에서 해당 숫자를 뺀 만큼 +1 또는 -1 하는 경우
    //2. 해당 숫자에서 가까운 숫자를 만든뒤 +1 또는 -1 하는 경우
    // 2가지 경우를 생각해보고 비교해서 가장 적은 버튼을 누르는 횟수를 정답으로

    // 고장난 버튼이 없을 수도 있다. 여기서 더 이상 입력이 없는지 판단한다.

    while (1) {

        if(cin.eof()) break;
        cin >> error_num;

        for (int i = 0; i < error_num; i++) {
            char a;
            cin >> a;
            broken_number.push_back(a);
        }
        break;

    }


    bool check = false;
    int ans = abs(n - 100);


    for (int i = 0; i <= 1000000; i++) {

        int case2;

        string str = "";

        str = to_string(i);


        for (int j = 0; j < broken_number.size(); j++) {

            if (str.find(broken_number[j]) != string::npos) { // 고장난 버튼이 있으면 탐색 중지
                check = true;
                break;
            }

        }

        if (check) {
            check = false;
            continue;
        }

        case2 = str.size() + abs(n - i);
        ans = min(ans, case2);

    }


    cout << ans;




    return 0;
}