#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define NMAX 98765


using namespace std;
int n, m;
int city[51][51];
int visited[14];
int visited2[51][51];

vector<pair<int,int>> house;
vector<int> chosen;
vector<pair<int, int>> shop;

int sum = 0;
int per_house_sum = NMAX;
int ans = NMAX;



void bt(int cnt){

    if (chosen.size() >= m) {

        sum = 0;

        for (int i = 0; i < house.size(); i++) {
            per_house_sum = NMAX;
            int cur_x = house[i].first;
            int cur_y = house[i].second;
            int dist;
            for (int j = 0; j < chosen.size(); j++) {
                int shop_x = shop[chosen[j]].first;
                int shop_y = shop[chosen[j]].second;
                dist = abs(shop_x - cur_x) + abs(shop_y - cur_y);
                per_house_sum = min(per_house_sum, dist);

            }
            sum += per_house_sum;
        }
        ans = min(ans, sum);

        //cout << "\n";
        return;
    }


    for (int i = 0; i < shop.size(); i++) {

        if(!chosen.empty() && chosen.back() > i) continue;

        if (!visited[i]) {
            visited[i] = 1;
            chosen.push_back(i);
            bt(cnt + 1);
            chosen.pop_back();
            visited[i] = 0;
        }

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;  //도시정보, 치킨집 갯수

    for (int y = 0; y < n; y++) {

        for (int x = 0; x < n; x++) {
            cin >> city[y][x];

            if (city[y][x] == 1) {
                house.push_back({x, y});
                visited2[y][x] = 1;
            } else if (city[y][x] == 2) {
                shop.push_back({x, y});
            }
        }
    }


    bt(0);

    cout << ans;

    return 0;
}