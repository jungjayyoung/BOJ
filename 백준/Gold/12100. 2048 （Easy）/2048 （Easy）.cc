#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int n;
int board[21][21];
int visited[21][21];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 2;


deque<int> tmp;

void all_deque_clear(deque<int> a[]){
    for (int i = 0; i < n; i++) {
        a[i].clear();
    }
}

void bt(deque<int> r[], deque<int> c[],int cnt){

    int r1[21][21] = {0,};
    int c1[21][21] = {0,};
    int r1_size[21] = {0,};
    int c1_size[21] = {0,};

    // row 덱 원소 저장
    for (int i = 0; i < n; i++) {
        r1_size[i] = r[i].size();

        for (int j = 0; j < r[i].size(); j++) {
            r1[i][j] = r[i][j];
        }
    }

    // col 덱 원소 저장
    for (int i = 0; i < n; i++) {
        c1_size[i] = c[i].size();

        for (int j = 0; j < c[i].size(); j++) {
            c1[i][j] = c[i][j];
        }
    }


//    for (int i = 0; i < n; i++) {
//
//        for (int j = 0; j < r[i].size(); j++) {
//            cout << r[i][j] << " ";
//        }
//        cout << "\n";
//
//    }
//    cout << "cnt: " << cnt;
//    cout << "\n";

    if (cnt >= 5) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < c[i].size(); j++) {
                ans = max(ans, c[i][j]);
            }
        }
        return;
    }

    //0: 위, 1: 오른쪽, 2: 아래쪽, 3: 왼쪽
    for (int i = 0; i < 4; i++) {

        all_deque_clear(r);
        all_deque_clear(c);

        // 덱 r 채우기
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < r1_size[k]; l++) {
                r[k].push_back(r1[k][l]);
            }
        }
        // 덱 c 채우기
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < c1_size[k]; l++) {
                c[k].push_back(c1[k][l]);
            }

        }
        tmp.clear();

        if (i == 0) { // 위쪽
            all_deque_clear(r);
            for (int j = 0; j < n; j++) {
                int a, b;
                a = 0;
                b = 0;
                while(!c[j].empty() || a != 0) {

                    int sum;

                    if (!c[j].empty() && a == 0) {
                        a = c[j].front();
                        c[j].pop_front();
                    }

                    if (!c[j].empty() && b == 0) {
                        b = c[j].front();
                        c[j].pop_front();
                    }

                    if (a == b && a != 0) {
                        sum = a + b;
                        tmp.push_back(sum);
                        a = 0;
                        b = 0;
                    } else if (a != 0) {
                        tmp.push_back(a);
                        a = b;
                        b = 0;
                    }

                }

                int idx = 0;
                while (!tmp.empty()) {
                    int cc = tmp.front();
                    c[j].push_back(cc);
                    r[idx].push_back(cc);
                    tmp.pop_front();
                    idx++;
                }

            }

            bt(r, c, cnt + 1);




        } else if (i == 1) { //오른쪽

            all_deque_clear(c);
            for (int j = 0; j < n; j++) {
                int a, b;
                a = 0;
                b = 0;
                while(!r[j].empty() || a != 0) {

                    int sum;

                    if (!r[j].empty() && a == 0) {
                        a = r[j].back();
                        r[j].pop_back();
                    }

                    if (!r[j].empty() && b == 0) {
                        b = r[j].back();
                        r[j].pop_back();
                    }

                    if (a == b && a != 0) {
                        sum = a + b;
                        tmp.push_front(sum);
                        a = 0;
                        b = 0;
                    } else if (a != 0) {
                        tmp.push_front(a);
                        a = b;
                        b = 0;
                    }

                }

                int idx = n - 1;
                while (!tmp.empty()) {
                    int cc = tmp.back();
                    c[idx].push_back(cc);
                    r[j].push_front(cc);

                    tmp.pop_back();
                    idx--;
                }

            }

            bt(r, c, cnt + 1);

        } else if (i == 2) {//아래쪽

            all_deque_clear(r);
            for (int j = 0; j < n; j++) {
                int a, b;
                a = 0;
                b = 0;
                while(!c[j].empty() || a != 0) {

                    int sum;

                    if (!c[j].empty() && a == 0) {
                        a = c[j].back();
                        c[j].pop_back();
                    }

                    if (!c[j].empty() && b == 0) {
                        b = c[j].back();
                        c[j].pop_back();
                    }

                    if (a == b && a != 0) {
                        sum = a + b;
                        tmp.push_front(sum);
                        a = 0;
                        b = 0;
                    } else if (a != 0) {
                        tmp.push_front(a);
                        a = b;
                        b = 0;
                    }

                }

                int idx = n-1;
                while (!tmp.empty()) {
                    int cc = tmp.back();
                    c[j].push_front(cc);
                    r[idx].push_back(cc);
                    tmp.pop_back();
                    idx--;
                }

            }
            bt(r, c, cnt + 1);


        } else if (i == 3) { // 왼쪽

            all_deque_clear(c);
            for (int j = 0; j < n; j++) {
                int a, b;
                a = 0;
                b = 0;
                while(!r[j].empty() || a != 0) {

                    int sum;

                    if (!r[j].empty() && a == 0) {
                        a = r[j].front();
                        r[j].pop_front();
                    }

                    if (!r[j].empty() && b == 0) {
                        b = r[j].front();
                        r[j].pop_front();
                    }

                    if (a == b && a != 0) {
                        sum = a + b;
                        tmp.push_back(sum);
                        a = 0;
                        b = 0;
                    } else if (a != 0) {
                        tmp.push_back(a);
                        a = b;
                        b = 0;
                    }

                }

                int idx = 0;
                while (!tmp.empty()) {
                    int cc = tmp.front();
                    c[idx].push_back(cc);
                    r[j].push_back(cc);

                    tmp.pop_front();
                    idx++;
                }

            }

            bt(r, c, cnt + 1);


        }

    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    deque<int> row[21];
    deque<int> col[21];
    cin >> n;

    for (int y = 0; y < n; y++) {

        for (int x = 0; x < n; x++) {

            cin >> board[y][x];
            if (board[y][x] != 0) {
                row[y].push_back(board[y][x]);
                col[x].push_back(board[y][x]);
            }

        }
    }

    bt(row, col, 0);


    cout << ans;



    return 0;
}