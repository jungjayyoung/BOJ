#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, l, k;

vector<pair<int,int>> rocks;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> l >> k;


    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        rocks.push_back({a, b});
    }

    int ans = 0;


    for (int i = 0; i < rocks.size(); i++) {



        for (int j = 0; j < rocks.size(); j++) {



            int x = rocks[i].first;
            int y = rocks[j].second;
            int cnt = 0;
            for (int c = 0; c < rocks.size(); c++) {

                int curx = rocks[c].first;
                int cury = rocks[c].second;

                if(x <= curx && curx <= x +l && y <= cury && cury <= y + l){
                    cnt++;
                }


            }

            ans = max(ans, cnt);
        }

    }

    cout << rocks.size() - ans;
    return 0;
}