#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,k;
int visited[100001];
int cache[100001];
int ans_cnt = 0;
int ans_time = 987654321;
queue<pair<int,int>> q;

void bfs(){

    q.push({n, 0});
    visited[n] = 1;

    while (!q.empty()) {

        int cur_pos = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();

        visited[cur_pos] = 1;


        // 한 번 목적지에 방문학 적이 있는 경우
        if (ans_time == cur_cnt && cur_pos == k) {

            ans_cnt++;

        }
        // 어차피 처음 k를 만났을 때가 최소 시간이 나온다
        if (cur_pos == k && ans_time == 987654321) {

            ans_time = min(ans_time, cur_cnt);

            ans_cnt++;
            continue;

        }

        if (cur_pos != 0 && cur_pos * 2 <= 100000 && !visited[cur_pos * 2]) {

            q.push({cur_pos * 2, cur_cnt + 1});
        }

        if (cur_pos - 1 >= 0 && !visited[cur_pos - 1]) {

            q.push({cur_pos - 1, cur_cnt + 1});
        }

        if (cur_pos + 1 <= 100000 && !visited[cur_pos + 1]) {

            q.push({cur_pos + 1, cur_cnt + 1});
        }






    }




}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    fill(cache, cache + 100001, 987654321);

    bfs();

    cout << ans_time << "\n";
    cout << ans_cnt;



    return 0;
}