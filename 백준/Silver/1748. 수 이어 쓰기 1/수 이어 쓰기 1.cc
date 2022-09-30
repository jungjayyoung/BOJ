#include <iostream>


using namespace std;

typedef long long ll;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >>n;

    ll ans = 0;
    if(n > 9) {
        ans +=9;
    }else{
        ans += n;
        cout << ans;
        return 0;
    }
    if(n > 99) {
        ans += (ll)90 * 2;
    }else{
        ans += (ll)(n - 9) * 2;
        cout << ans;
        return 0;
    }
    if(n > 999) {
        ans += (ll)900 * 3;
    }else{
        ans += (ll)(n - 99) * 3;
        cout << ans;
        return 0;
    }
    if(n > 9999) {
        ans += (ll)9000 * 4;
    }else{
        ans += (ll)(n - 999) * 4;
        cout << ans;
        return 0;
    }
    if(n > 99999) {
        ans += (ll)90000 * 5;
    }else{
        ans += (ll)(n - 9999) * 5;
        cout << ans;
        return 0;
    }
    if(n > 999999) {
        ans += (ll)900000 * 6;
    }else{
        ans += (ll)(n - 99999) * 6;
        cout << ans;
        return 0;
    }
    if(n > 9999999) {
        ans += (ll)9000000 * 7;
    }else{
        ans += (ll)(n - 999999) * 7;
        cout << ans;
        return 0;
    }
    if(n > 99999999) {
        ans += (ll)90000000 * 8;
    }else{
        ans += (ll)(n - 9999999) * 8;
        cout << ans;
        return 0;
    }



    cout << ans + 9;
    return 0;
}