#include <iostream>


typedef long long ll;
using namespace std;


int board[26][26];
int visited[26][26];
int n,m;
ll cnt = 0;
bool check = false;
void bt(int xx,int yy){



    if (yy >= n) {
//        check = false;
//        for (int y = 0; y < n - 1; y++) {
//
//            for (int x = 0; x < m - 1; x++) {
//
//                if(visited[y][x] && visited[y+1][x] && visited[y][x+1] && visited[y+1][x+1]){
//                    return;
//                }
//
//            }
//        }

        cnt++;
        return;
    }



    int nextx = xx + 1;
    int nexty = yy;

    if (nextx >= m) {
        nextx = 0;
        nexty++;
    }


    visited[yy][xx] = 1;
    bool check2 =false;

    if (xx >= 1 && yy >= 1) {
        if (visited[yy][xx] && visited[yy - 1][xx] && visited[yy][xx - 1] && visited[yy - 1][xx - 1]) {
            check2 = true;
        }
    }

    if(!check2)
        bt(nextx, nexty);
    visited[yy][xx] = 0;
    bt(nextx, nexty);

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    bt(0, 0);

    cout <<cnt;

    return 0;
}