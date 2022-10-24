#include <iostream>
#include <vector>
#define MOD 1000
typedef long long ll;
using namespace std;


ll n,b;

vector<vector<ll>> origin(5, vector<ll>(5));


vector<vector<ll>> matrix_mul(vector<vector<ll>> a1,vector<vector<ll>> a2){

    vector<vector<ll>> sum(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            for (int k = 0; k < n; k++) {
                sum[i][j] += a1[i][k] * a2[k][j];
                sum[i][j] %= MOD;

            }
        }

    }

    return sum;


}


vector<vector<ll>> matrix_pow(vector<vector<ll>> a1, ll b){

    if (b == 1) {

        return a1;
    }

    vector<vector<ll>> ret = matrix_pow(a1, b / 2);

    ret = matrix_mul(ret, ret);

    // 지수가 홀수면
    if (b % 2 == 1) {
        ret = matrix_mul(ret, origin);
    }


    return ret;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> b;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cin >> origin[i][j];
            origin[i][j] %= MOD;
        }

    }
    // n * n 크기의 벡터 선언
    vector<vector<ll>> v(n, vector<ll>(n));

    // 단위 행렬로 초기화

    for (int i = 0; i < n; i++) {
        v[i][i] = 1;
    }


    v = matrix_pow(origin, b);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";

    }


    return 0;
}