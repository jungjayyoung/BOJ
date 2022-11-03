#include <iostream>
#include <algorithm>


typedef long long ll;
using namespace std;

ll n, m;


ll five_cnt(ll num){

    ll cnt = 0;

    while (num >= 5) {

        cnt += num / 5;
        num/= 5;

    }

    return cnt;

}

ll two_cnt(ll num){

    ll cnt = 0;

    while (num >= 2) {
        cnt += num / 2;
        num /= 2;
    }

    return cnt;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;


    ll five = five_cnt(n) - five_cnt(n - m) - five_cnt(m);
    ll two = two_cnt(n) - two_cnt(n - m) - two_cnt(m);


    cout << min(five, two);

    return 0;
}

