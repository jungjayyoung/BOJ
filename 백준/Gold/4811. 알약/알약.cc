#include <iostream>
#include <string>
using namespace std;


typedef long long ll;


ll dp[61][61];


ll bt(int w_cnt,int h_cnt){

    if(w_cnt == 0) return 1;

    ll &cnt = dp[w_cnt][h_cnt];

    if(cnt != -1) return cnt;

    cnt = 0;

    // 큰알약을 하나 먹었을 경우
    if (w_cnt > 0) {
        cnt += bt(w_cnt - 1, h_cnt + 1);
    }
    //작은 알약을 하나 먹었을 경우
    if (h_cnt > 0) {
        cnt += bt(w_cnt, h_cnt - 1);
    }


    return cnt;


}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);



    while (1) {

        int n;
        cin >> n;

        if(n == 0) break;

        fill(&dp[0][0], &dp[61][0], -1);

        cout << bt(n - 1, 1) << "\n";

    }

    return 0;
}