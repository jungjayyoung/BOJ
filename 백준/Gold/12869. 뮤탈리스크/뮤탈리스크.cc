#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int visited[61][61][61];

int scv[3];

// 1 3 9
// 1 9 3
// 3 1 9

// 9 1 3
// 9 3 1
// 3 9 1

vector<pair<pair<int,int>,int>> dmg;

int n;


queue<pair<pair<int,int>,pair<int,int>>> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> scv[i];
    }
    dmg.push_back({{1, 3}, 9});
    dmg.push_back({{1, 9}, 3});
    dmg.push_back({{3, 1}, 9});
    dmg.push_back({{3, 9}, 1});
    dmg.push_back({{9, 3}, 1});
    dmg.push_back({{9, 1}, 3});

    q.push({{scv[0], scv[1]}, {scv[2],0}});
    visited[scv[0]][scv[1]][scv[2]] = 1; //처음 dp 0으로 초기화

    int ans = 12345679;
    while (!q.empty()) {

        int scv1 = q.front().first.first;
        int scv2 = q.front().first.second;
        int scv3 = q.front().second.first;
        int cnt = q.front().second.second;

        q.pop();

        if (scv1 <= 0 && scv2 <= 0 && scv3 <= 0) {
            ans = min(ans, cnt);
            break;
        }



        for (int i = 0; i < 6; i++) {
            int scv1_next = scv1 - dmg[i].first.first;
            int scv2_next = scv2 - dmg[i].first.second;
            int scv3_next = scv3 - dmg[i].second;

            if(scv1_next < 0) scv1_next = 0;
            if(scv2_next < 0) scv2_next = 0;
            if(scv3_next < 0) scv3_next = 0;

            if (visited[scv1_next][scv2_next][scv3_next]) continue;

            visited[scv1_next][scv2_next][scv3_next] = 1;
            q.push({{scv1_next, scv2_next}, {scv3_next,cnt + 1}});

        }



    }

    cout << ans;


    return 0;
}