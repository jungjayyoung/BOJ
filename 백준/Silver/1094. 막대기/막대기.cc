#include <iostream>
#include <vector>


using namespace std;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x;

    cin >> x;

    int num = 64;

    while (x < num) {
        num = num / 2;
    }
    while (num >= 1) {
        v.push_back(num);
        num = num >> 1;
    }
    v.push_back(1);

    int cnt = 0;
    for (auto i: v) {
        if (x >= i) {
            x -= i;
            cnt++;
        }
    }

    cout << cnt;


    return 0;
}