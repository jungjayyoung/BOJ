#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);



    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int sum = 0;

    for (int i = 0; i < 10; i++) {
        int num = v[i];

        if (abs(100 - (sum + num)) <= abs(100 - sum)) {
            sum += num;
        }else
            break;


    }

    cout << sum;



    return 0;
}