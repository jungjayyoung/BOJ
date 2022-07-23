#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>


using namespace std;


queue<pair<pair<int,int>,int>> q; // 개수, 초, 클립보드

int ans = 654321;
int s;
int dp[1002][1002]; // 현재 화면의 이모티콘 갯수, 현재 클립보드 안의 갯수

void bfs(){

    while (!q.empty()) {

        int cur_cnt = q.front().first.first;
        int cur_second = q.front().first.second;
        int cur_clip = q.front().second;

        q.pop();

        if (cur_cnt == s) {
            return;
        }

        // 1 빼기
        if((cur_cnt - 1 >= 1) && dp[cur_cnt-1][cur_clip] == -1){
            dp[cur_cnt - 1][cur_clip] = cur_second + 1;
            q.push({{cur_cnt - 1, cur_second + 1}, cur_clip});
        }

        //2. 클립보드 추가
        if (dp[cur_cnt][cur_cnt] == -1) {
            q.push({{cur_cnt, cur_second + 1}, cur_cnt});
            dp[cur_cnt][cur_cnt] = cur_second + 1;
        }

        //3. 클립보드 붙여넣기
        if ( dp[cur_cnt + cur_clip][cur_clip] == -1 && cur_clip > 0 && cur_cnt + cur_clip <= 1001) {
            q.push({{cur_cnt + cur_clip, cur_second + 1}, cur_clip});
            dp[cur_cnt + cur_clip][cur_clip] = cur_second + 1;
        }

    }


}





int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);



    cin >> s;

    fill(&dp[0][0], &dp[1001][0], -1);
    q.push({{1, 0}, 0});
    dp[1][0] = 0;
    bfs();


    for (int i = 0; i <= 1001; i++) {
        if(dp[s][i] == -1 || dp[s][i] == 0) continue;
        ans = min(ans, dp[s][i]);
    }

    cout << ans;

    return 0;
}