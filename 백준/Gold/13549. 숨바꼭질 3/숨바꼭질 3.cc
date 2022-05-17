#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int n,k;
int visited[100001];
int cache[100001]; // cache[n] : 점 n까지 도달하는데 걸리는 최소시간 저장

void bfs(){

    deque<pair<int,int>> q; // 현재 위치, 현재위치까지 가는데 걸리는 시간
    q.push_back({n, 0});
    visited[n] = 1;

    while (!q.empty()) {

        int cur_pos = q.front().first;
        int cur_time = q.front().second;
        q.pop_front();



        if (cur_pos == k) {

            cout << cur_time;
            return;
        }


        // 3가지 경우 생각

        // 3. 2*x 이동
        if (cur_pos * 2 <= 100000 && !visited[cur_pos * 2]) {
            visited[cur_pos * 2] = 1;
            q.push_front({cur_pos * 2, cur_time});
        }

        // 1. x- 1 이동
        if (cur_pos - 1 >= 0 && !visited[cur_pos - 1]) {

            visited[cur_pos - 1] = 1;
            q.push_back({cur_pos - 1, cur_time + 1});
        }
        // 2. x + 1 이동
        if (cur_pos + 1 <= 100000 && !visited[cur_pos + 1]) {
            visited[cur_pos + 1] = 1;
            q.push_back({cur_pos + 1, cur_time + 1});
        }



    }






}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >>k;

    fill(cache, cache + 100001, 987654321);



    bfs();



    return 0;
}