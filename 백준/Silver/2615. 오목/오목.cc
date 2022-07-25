#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[20][20];


int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool cmp(pair<int, int> a, pair<int, int> b){

    if (a.first != b.first) {
        return a.first <b.first;
    }else{
        return a.second < b.second;
    }


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    for (int y = 0; y < 19; y++) {

        for (int x = 0; x < 19; x++) {

            cin >> board[y][x];
        }
    }

    bool white = false;
    bool black = false;
    int nx = 99,ny = 99;

    for (int y = 0; y < 19; y++) {

        for (int x = 0; x < 19; x++) {
            nx = x;
            ny = y;



            if (board[y][x] == 1) {

                int cnt = 1;
                for (int i = 0; i < 4; i++) {

                    vector<pair<int,int>> v;
                    cnt = 1;

                    int k = 1;
                    v.push_back({x, y});

                    // 1번째 방향

                    while (x + dx[i] * k >= 0 && y + dy[i] * k >= 0 && x + dx[i] * k < 19 && y + dy[i] * k < 19) {
                        if (board[y + dy[i] * k][x + dx[i] * k] == 1) {

                            v.push_back({x + dx[i] * k, y + dy[i] * k});

                            cnt++;
                            k++;
                        }else{
                            break;
                        }
                    }

                    k = 1;

                    // 반대 방향
                    while (x + dx[i + 4] * k >= 0 && y + dy[i + 4] * k >= 0 && x + dx[i + 4] * k < 19 && y + dy[i + 4] * k < 19) {
                        if (board[y + dy[i + 4] * k][x + dx[i + 4] * k] == 1) {
                            v.push_back({x + dx[i+ 4] * k, y + dy[i + 4] * k});
                            cnt++;
                            k++;
                        }else{
                            break;
                        }
                    }

                    if (cnt == 5) {
                        sort(v.begin(), v.end());
                        nx = v[0].first;
                        ny = v[0].second;
                        black = true;
                        break;
                    }

                }

            }else if(board[y][x] == 2){

                int cnt = 1;
                for (int i = 0; i < 4; i++) {
                    vector<pair<int,int>> v;
                    v.push_back({x, y});

                    cnt = 1;
                    int k = 1;
                    // 1번째 방향

                    while (x + dx[i] * k >= 0 && y + dy[i] * k >= 0 && x + dx[i] * k < 19 && y + dy[i] * k < 19) {
                        if (board[y + dy[i] * k][x + dx[i] * k] == 2) {
                            v.push_back({x + dx[i] * k, y + dy[i] * k});
                            cnt++;
                            k++;
                        }else{
                            break;
                        }
                    }

                    k = 1;

                    // 반대 방향
                    while (x + dx[i + 4] * k >= 0 && y + dy[i + 4] * k >= 0 && x + dx[i + 4] * k < 19 && y + dy[i + 4] * k < 19) {
                        if (board[y + dy[i + 4] * k][x + dx[i + 4] * k] == 2) {
                            v.push_back({x + dx[i + 4] * k, y + dy[i + 4] * k});
                            cnt++;
                            k++;
                        }else{
                            break;
                        }
                    }

                    if (cnt == 5) {
                        sort(v.begin(), v.end());
                        
                        nx = v[0].first;
                        ny = v[0].second;
                        white = true;
                        break;
                    }

                }
            }

            if (white || black) {
                break;
            }


        }
        if (white || black) {
            break;
        }

    }

    if (white) {
        cout << 2 << "\n";
        cout << ny + 1 << " " << nx + 1;
    }else if(black){
        cout << 1 << "\n";
        cout << ny + 1 << " " << nx + 1;
    }else
        cout << 0;




    return 0;
}