#include <iostream>
#include <vector>

using namespace std;

int n, k, r, c;

bool check[9]; // 0번째가 백색킹의 위치
vector<pair<int,int>> king;

int dx[] = {0, -1, -1, 0, -1, 0, 1, 1, 1};
int dy[] = {0, 0, -1, 1, 1, -1, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> k;
    cin >> r >> c;

    for (int i = 0; i < 9; i++) {
        int ny = r + dy[i];
        int nx = c + dx[i];

        if(nx < 1 || ny < 1 || nx > n || ny >n) continue;
        king.push_back({nx, ny});
    }

    // check의 0번째가 현재 킹의 위치이다.
    // 킹의 크기가 킹이 갈 수 있는 곳의 총 개수다.
    for (int i = 0; i < k; i++) {
        int cury, curx;
        cin >> cury >> curx;

        for (int j = 0; j < king.size(); j++) {
            int kx = king[j].first;
            int ky = king[j].second;

            if ((kx == curx || ky == cury)) {
                check[j] = true;
                continue;
            }
            double l = (double)(kx - curx) / (ky - cury);

            if (l == 1 || l == -1) {
                check[j] = true;
            }

        }
    }

    bool check2 = false;
    bool checkmate = true;

    for (int i = 0; i < king.size(); i++) {
        if (i == 0 && check[i]) {
            check2 = true;
        } else if (i != 0 && check[i] == 0) {
            checkmate = false;
        }
    }

    if (!check2 && checkmate) {
        cout << "STALEMATE";
    } else if (check2 && !checkmate) {
        cout << "CHECK";
    } else if (checkmate && check2) {
        cout << "CHECKMATE";
    }else{
        cout << "NONE";
    }


    return 0;
}