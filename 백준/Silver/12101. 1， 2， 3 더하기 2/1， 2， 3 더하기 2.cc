#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

typedef long long ll;
ll n,k;

vector<int> v;
ll cnt = 1;
bool check = false;

void bt(int sum){

    if (sum >= n) {

        if (sum == n) {

            if (cnt == k) {
                for (int i = 0; i < v.size(); i++) {
                    cout << v[i];
                    if (i != v.size() - 1) {
                        cout << '+';
                    }
                }
                check = true;
                return;
            }
            cnt++;
        }


        return;
    }

    for (int i = 1; i <= 3; i++) {

        if (sum + i <= n) {
            v.push_back(i);
            bt(sum + i);
            v.pop_back();
        }

        if (check) {
            return;
        }

    }



}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> k;


    bt(0);

    if (!check) {
        cout << -1;
    }


    return 0;
}