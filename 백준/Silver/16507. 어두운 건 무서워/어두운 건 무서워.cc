#include <iostream>

using namespace std;

int map[1001][1001];
int sum[1001][1001];
int r, c, q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> q;

    for (int y = 1; y <= r; y++) {
        for (int x = 1; x <= c; x++) {
            cin >> map[y][x];
        }
    }

    // 1. 행 배열 누적 합 구하기
    for (int y = 1; y <= r; y++) {
        for (int x = 1; x <= c; x++) {
            if (x == 1) {
                sum[y][x] = map[y][x];
            }else
                sum[y][x] = sum[y][x - 1] + map[y][x];
        }
    }
    //2. 열 누적 합 구하기
    for (int x = 1; x <= c; x++) {
        for (int y = 2; y <= r; y++) {
            sum[y][x] = sum[y - 1][x] + sum[y][x];
        }
    }

    while (q--) {
        int a, b, c, d;

        cin >> a >> b >> c >> d;
        int num = (c - a + 1) * (d - b + 1);

        cout << (sum[c][d] - (sum[c][b - 1] + sum[a - 1][d]) + sum[a - 1][b - 1]) / num << "\n";

    }

}