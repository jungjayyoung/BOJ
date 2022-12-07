#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> pos[4];

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    int res = a.first * b.second + b.first * c.second + c.first * a.second;

    res -= (a.first * c.second + b.first * a.second + c.first * b.second);

    if(res > 0) return 1;
    else if(res == 0) return 0;
    else return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    // 둘 다 0이라면 두 선분이 같은 선상에 평행하다는 뜻이다.
    int r1 = ccw(pos[0], pos[1], pos[2]) * ccw(pos[0], pos[1], pos[3]);
    int r2 = ccw(pos[2], pos[3], pos[0]) * ccw(pos[2], pos[3], pos[1]);

    if (r1 < 0 && r2 < 0) {
        cout << 1;
    }else
        cout << 0;
}