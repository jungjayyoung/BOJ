#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


int visited[101];
vector<pair<int, int>> v; // 편의점 좌표
queue<pair<int,int>> q;

int n;
int d_x,d_y;
int s_x,s_y;
bool check = false;

void bfs(){


    while (!q.empty()) {

        int cur_x = q.front().first;
        int cur_y = q.front().second;

        q.pop();

        if (abs(cur_x - d_x) + abs(cur_y - d_y) <= 1000) {

            check = true;
            return;
        }

        for (int i = 0; i < n; i++) {

            int nextx = v[i].first;
            int nexty = v[i].second;

            if(visited[i]) continue;

            if (abs(cur_x - nextx) + abs(cur_y - nexty) <= 1000) {
                visited[i] = 1;
                q.push({nextx, nexty});
            }


        }



    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--) {

        memset(visited, 0, sizeof(visited));
        check = false;

        cin >> n;
        cin >> s_x >> s_y;

        q.push({s_x, s_y});

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});

            if (abs(x - s_x) + abs(y - s_y) <= 1000) {
                q.push({x, y});
                visited[i] = 1;
            }

        }

        cin >> d_x >> d_y;

        bfs();

        if (check) {
            cout << "happy" << "\n";
        }else
            cout << "sad" << "\n";

        while (!q.empty()) {
            q.pop();
        }

        v.clear();



    }


    return 0;
}