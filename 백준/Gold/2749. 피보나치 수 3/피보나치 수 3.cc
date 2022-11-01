#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000

typedef long long ll;

using namespace std;

int cnt = 1;

vector<vector<ll>> b = {{1, 1}, {1, 0}};
vector<vector<ll>> origin = {{1, 1}, {1, 0}};

vector<vector<ll>> matrix_pow(vector<vector<ll>> a1,vector<vector<ll>> a2){

    vector<vector<ll>> res(2, vector<ll>(2));

    for (int y = 0; y < 2; y++) {

        for (int x = 0; x < 2; x++) {

            for (int k = 0; k < 2; k++) {
                res[y][x] += a1[y][k] * a2[k][x];
                res[y][x] %= MOD;
            }
        }
    }

    return res;

}

vector<vector<ll>> solve(vector<vector<ll>> sum,ll num){

    cnt++;
    if (num == 1) {
        return sum;
    }else{
        vector<vector<ll>> x = solve(sum, num / 2);

        if (num % 2 == 0) {
            return matrix_pow(x, x);
        }else{
            return matrix_pow(matrix_pow(x, x), origin);
        }

    }


}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    vector<vector<ll>> ans(2, vector<ll>(2));


    ll n;

    cin >> n;

    if (n == 1) {
        cout << 1;
        return 0;
    }
    ans = solve(b, n - 1);

    cout << ans[0][0];

    return 0;
}