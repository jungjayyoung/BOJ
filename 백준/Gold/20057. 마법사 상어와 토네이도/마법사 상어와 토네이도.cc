#include <iostream>


using namespace std;

int n;

int map[501][501];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


int ans = 0;

void move(int sx, int sy, int dir){


    int yy;
    int sum = 0;

    if (dir == 0) {

        yy = map[sy][sx - 1];

        // 5%
        if (sx - 3 > 0) {
            map[sy][sx - 3] += (yy * 5) / 100;
            sum += (yy * 5) / 100;
        }else{
            ans += (yy * 5) / 100;
            sum += (yy * 5) / 100;
        }

        // 10%
        if (sx - 2 > 0 && sy - 1 > 0) {
            map[sy - 1][sx - 2] += (yy * 10) / 100;
            sum += (yy * 10) / 100;
        }else{
            ans += (yy * 10) / 100;
            sum += (yy * 10) / 100;
        }

        if (sx - 2 > 0 && sy + 1 <= n) {
            map[sy + 1][sx - 2] += (yy * 10) / 100;
            sum += (yy * 10) / 100;
        }else{
            ans += (yy * 10) / 100;
            sum += (yy * 10) / 100;
        }

        // 7%
        if (sx - 1 > 0 && sy - 1 > 0) {
            map[sy - 1][sx - 1] += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        } else {
            ans += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        }

        if (sx - 1 > 0 && sy + 1 <= n) {
            map[sy + 1][sx - 1] += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        } else {
            ans += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        }

        //2%
        if (sx - 1 > 0 && sy - 2 > 0) {
            map[sy - 2][sx - 1] += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        } else {
            ans += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        }

        if (sx - 1 > 0 && sy + 2 <= n) {
            map[sy + 2][sx - 1] += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        } else {
            ans += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        }

        // 1%
        if (sy - 1 > 0) {
            map[sy - 1][sx] += (yy * 1) / 100;
            sum += (yy * 1) / 100;
        } else {
            ans += (yy * 1) / 100;
            sum += (yy * 1) / 100;
        }

        if (sy + 1 <= n) {
            map[sy + 1][sx] += (yy * 1) / 100;
            sum += (yy * 1) / 100;
        } else {
            ans += (yy * 1) / 100;
            sum += (yy * 1) / 100;
        }

        if (sx - 2 > 0) {
            map[sy][sx - 2] += (yy - sum);
        }else
            ans += (yy - sum);

        map[sy][sx - 1] = 0;


    } else if (dir == 1) {
        yy = map[sy + 1][sx];

        // 5%
        if (sy + 3 <= n) {
            map[sy + 3][sx] += (yy * 5) / 100;
            sum += (yy * 5) / 100;
        }else{
            ans += (yy * 5) / 100;
            sum += (yy * 5) / 100;
        }

        // 10%
        if (sy + 2 <= n && sx - 1 > 0) {
            map[sy + 2][sx - 1] += (yy * 10) / 100;
            sum += (yy * 10) / 100;
        }else{
            ans += (yy * 10) / 100;
            sum += (yy * 10) / 100;
        }

        if (sy + 2 <= n && sx + 1 <= n) {
            map[sy + 2][sx + 1] += (yy * 10) / 100;
            sum += (yy * 10) / 100;
        }else{
            ans += (yy * 10) / 100;
            sum += (yy * 10) / 100;
        }

        // 7%
        if (sx + 1 <= n && sy + 1 <= n) {
            map[sy + 1][sx + 1] += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        } else {
            ans += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        }

        if (sx - 1 > 0 && sy + 1 <= n) {
            map[sy + 1][sx - 1] += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        } else {
            ans += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        }

        //2%
        if (sy + 1 <= n && sx + 2 <= n) {
            map[sy + 1][sx + 2] += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        } else {
            ans += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        }

        if (sy + 1 <= n && sx - 2 > 0) {
            map[sy + 1][sx - 2] += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        } else {
            ans += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        }

        // 1%
        if (sx + 1 <= n) {
            map[sy][sx + 1] += (yy * 1) / 100;
            sum += (yy * 1) / 100;
        } else {
            ans += (yy * 1) / 100;
            sum += (yy * 1) / 100;
        }

        if (sx - 1 > 0) {
            map[sy][sx - 1] += (yy * 1) / 100;
            sum += (yy * 1) / 100;
        } else {
            ans += (yy * 1) / 100;
            sum += (yy * 1) / 100;
        }


        if (sy + 2 <= n) {
            map[sy + 2][sx] += (yy - sum);
        }else
            ans += (yy - sum);

        map[sy + 1][sx] = 0;


    } else if (dir == 2) {
        yy = map[sy][sx + 1];

        // 5%
        if (sx + 3 <= n) {
            map[sy][sx + 3] += (yy * 5) / 100;
            sum += (yy * 5) / 100;
        }else{
            ans += (yy * 5) / 100;
            sum += (yy * 5) / 100;
        }

        // 10%
        if (sx + 2 <= n && sy - 1 > 0) {
            map[sy - 1][sx + 2] += (yy * 10) / 100;
            sum += (yy * 10) / 100;
        }else{
            ans += (yy * 10) / 100;
            sum += (yy * 10) / 100;
        }

        if (sx + 2 <= n && sy + 1 <= n) {
            map[sy + 1][sx + 2] += (yy * 10) / 100;
            sum += (yy * 10) / 100;
        }else{
            ans += (yy * 10) / 100;
            sum += (yy * 10) / 100;
        }

        // 7%
        if (sx + 1 <= n && sy - 1 > 0) {
            map[sy - 1][sx + 1] += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        } else {
            ans += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        }

        if (sx + 1 <= n && sy + 1 <= n) {
            map[sy + 1][sx + 1] += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        } else {
            ans += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        }

        //2%
        if (sx + 1 <= n && sy - 2 > 0) {
            map[sy - 2][sx + 1] += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        } else {
            ans += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        }

        if (sx + 1 <= n && sy + 2 <= n) {
            map[sy + 2][sx + 1] += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        } else {
            ans += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        }

        // 1%
        if (sy - 1 > 0) {
            map[sy - 1][sx] += (yy * 1) / 100;
            sum += (yy * 1) / 100;
        } else {
            ans += (yy * 1) / 100;
            sum += (yy * 1) / 100;
        }

        if (sy + 1 <= n) {
            map[sy + 1][sx] += (yy * 1) / 100;
            sum += (yy * 1) / 100;
        } else {
            ans += (yy * 1) / 100;
            sum += (yy * 1) / 100;
        }


        if (sx + 2 <= n) {
            map[sy][sx + 2] += (yy - sum);
        }else
            ans += (yy - sum);

        map[sy][sx + 1] = 0;
    } else if (dir == 3) {
        yy = map[sy - 1][sx];

        // 5%
        if (sy - 3 > 0) {
            map[sy - 3][sx] += (yy * 5) / 100;
            sum += (yy * 5) / 100;
        }else{
            ans += (yy * 5) / 100;
            sum += (yy * 5) / 100;
        }

        // 10%
        if (sx + 1 <= n && sy - 2 > 0) {
            map[sy - 2][sx + 1] += (yy * 10) / 100;
            sum += (yy * 10) / 100;
        }else{
            ans += (yy* 10) / 100;
            sum += (yy * 10) / 100;
        }

        if (sx - 1 > 0 && sy - 2 > 0) {
            map[sy - 2][sx - 1] += (yy * 10) / 100;
            sum += (yy * 10) / 100;
        }else{
            ans += (yy * 10) / 100;
            sum += (yy * 10) / 100;
        }

        // 7%
        if (sx + 1 <= n && sy - 1 > 0) {
            map[sy - 1][sx + 1] += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        } else {
            ans += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        }

        if (sx - 1 > 0 && sy - 1 > 0) {
            map[sy - 1][sx - 1] += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        } else {
            ans += (yy * 7) / 100;
            sum += (yy * 7) / 100;
        }

        //2%
        if (sx + 2 <= n && sy - 1 > 0) {
            map[sy - 1][sx + 2] += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        } else {
            ans += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        }

        if (sx - 2 > 0 && sy - 1 > 0) {
            map[sy - 1][sx - 2] += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        } else {
            ans += (yy * 2) / 100;
            sum += (yy * 2) / 100;
        }

        // 1%
        if (sx - 1 > 0) {
            map[sy][sx - 1] += (yy * 1) / 100;
            sum += (yy * 1) / 100;

        } else {
            ans += (yy * 1) / 100;
            sum += (yy * 1) / 100;
        }

        if (sx + 1 <= n) {
            map[sy][sx + 1] += (yy * 1) / 100;
            sum += (yy * 1) / 100;
        } else {
            ans += (yy * 1) / 100;
            sum += (yy * 1) / 100;
        }


        if (sy - 2 > 0) {
            map[sy - 2][sx] += (yy - sum);
        }else
            ans += (yy - sum);

        map[sy - 1][sx] = 0;

    }






}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;

    for (int y = 1; y <= n; y++) {

        for (int x = 1; x <= n; x++) {
            cin >> map[y][x];
        }
    }

    int stx = n / 2 + 1;
    int sty = n / 2 + 1;
    int d = 0;
    int cnt = 1;
    int cntt = 0;


    while (stx != 1 || sty != 1) {

        for (int i = 0; i < cnt; i++) {
            move(stx, sty, d);
            stx = stx + dx[d];
            sty = sty + dy[d];
            if(stx == 1 && sty == 1) break;
        }




        cntt++;
        if (cntt == 2) {
            cnt++;
            cntt = 0;
        }
        d++;
        if (d == 4) {
            d = 0;
        }

    }


    cout << ans;





    return 0;
}