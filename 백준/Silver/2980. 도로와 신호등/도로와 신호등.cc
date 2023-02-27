#include <iostream>


using namespace std;

int n, l;





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l;

    // 알아야 되는 정보
    // 1. 현재 시간, 현재 위치
    // 2. 현재 시간 % (r + g) == 0 || 현재 시간 % (r + g) > r 이면 초록불

    int cur_time = 0;
    int cur_loc = 0;

    for (int i = 0; i < n; i++) {
        int d, r, g;
        cin >> d >> r >> g;


        // 현재 신호등이 빨간불이면?
        if ((cur_time + (d - cur_loc)) % (r + g) <= r) {
            cur_time += r - ((cur_time + (d - cur_loc)) % (r + g)) + (d - cur_loc);
            cur_loc = d;

        } else {
            // 현재 신호등이 초록불이면?
            cur_time = cur_time + (d - cur_loc);
            cur_loc = d;
        }

    }
    cout << cur_time + (l - cur_loc);

    return 0;
}