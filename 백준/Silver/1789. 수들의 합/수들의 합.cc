#include <iostream>


using namespace std;
typedef long long ll;
ll s;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> s;

    ll sum = 0;


    ll cnt = 0;
    for (ll i = 1; i <= s; i++) {

        sum += i;
        cnt++;
        if(sum > s){
            cnt--;
            break;
        }else if(sum == s){
            break;
        }

    }

    cout << cnt;


    return 0;
}