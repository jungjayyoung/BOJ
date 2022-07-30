#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


// 상어의 인덱스를 저장한다. 0이면 아무것도 없다는 뜻
// 다른게 있으면 잡아먹는다.

vector<int> board[101][101];
int moved_board[101][101];

int r,c,m;

struct Shark{
    int y;
    int x;
    int speed;
    int dir;
    int size;
    bool is_move = false;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Shark shark[10001];
    cin >> r >> c >> m;



    for (int i = 1; i <= m; i++) {
        int y,x,s,d,z; // y좌표, x좌표, 속도, 이동방향, 크기
        cin >> y >> x >> s >> d >> z;
        board[y][x].push_back(i);
        shark[i].y = y;
        shark[i].x = x;
        shark[i].speed = s;
        shark[i].dir = d;
        shark[i].size = z;
    }


    // 1,1 부터 시작한다.
    int sum = 0;
    for (int x = 1; x <= c; x++) {

        // 1. 1칸 씩 이동
        for(int y = 1; y <= r; y++){
            // 2. 낚시왕과 가장 가까운 상어를 먹는다
            if(!board[y][x].empty()){
                sum += shark[board[y][x][0]].size;
                board[y][x].pop_back();
                break;

            }
        }
        fill(&moved_board[0][0], &moved_board[101][0], -1);
        //3. 상어가 이동한다.
        for (int xx = 1; xx <= c; xx++) {

            for (int yy = 1; yy <= r; yy++) {
                if (!board[yy][xx].empty()) {
                    int cur_idx = board[yy][xx][0];
                    board[yy][xx].pop_back();
                    int nexty = shark[cur_idx].y;
                    int nextx = shark[cur_idx].x;

                    // 위
                    if (shark[cur_idx].dir == 1) {
                        nexty = shark[cur_idx].y - shark[cur_idx].speed;
                        nextx = shark[cur_idx].x;
                        while (nexty < 1 || nexty > r) {
                            if (nexty < 1) {
                                nexty = 2 - nexty;
                                shark[cur_idx].dir = 2;
                            } else if (nexty > r) {
                                nexty = r - (nexty - r);
                                shark[cur_idx].dir = 1;
                            }
                        }
                        shark[cur_idx].y = nexty;
                        shark[cur_idx].x = nextx;

                   // 아래
                    }else if(shark[cur_idx].dir == 2){
                        nexty = shark[cur_idx].y + shark[cur_idx].speed;
                        nextx = shark[cur_idx].x;
                        while (nexty < 1 || nexty > r) {
                            if (nexty < 1) {
                                nexty = 2 - nexty;
                                shark[cur_idx].dir = 2;
                            } else if (nexty > r) {
                                nexty = r - (nexty - r);
                                shark[cur_idx].dir = 1;
                            }
                        }
                        shark[cur_idx].y = nexty;
                        shark[cur_idx].x = nextx;
                   // 오른쪽
                    }else if(shark[cur_idx].dir == 3){
                        nextx = shark[cur_idx].x + shark[cur_idx].speed;
                        nexty = shark[cur_idx].y;
                        while (nextx < 1 || nextx > c) {
                            if (nextx < 1) {
                                nextx = 2 - nextx;
                                shark[cur_idx].dir = 3;
                            } else if (nextx > c) {
                                nextx = c - (nextx - c);
                                shark[cur_idx].dir = 4;
                            }
                        }
                        shark[cur_idx].y = nexty;
                        shark[cur_idx].x = nextx;

                   // 왼쪽
                    }else if(shark[cur_idx].dir == 4){
                        nextx = shark[cur_idx].x - shark[cur_idx].speed;
                        nexty = shark[cur_idx].y;
                        while (nextx < 1 || nextx > c) {
                            if (nextx < 1) {
                                nextx = 2 - nextx;
                                shark[cur_idx].dir = 3;
                            } else if (nextx > c) {
                                nextx = c - (nextx - c);
                                shark[cur_idx].dir = 4;
                            }
                        }
                        shark[cur_idx].y = nexty;
                        shark[cur_idx].x = nextx;
                    }

                    // 다음 위치로 상어을 이동시킨다.
                    // 그런데 moved_board가 -1 이 아니면 다른 상어가 이미 존재하는 뜻이므로
                    // 그 상어와 크기 비교를 해서 큰 상어를 업데이트해준다.

                    int exist_shark_idx = moved_board[nexty][nextx];
                    if (exist_shark_idx != -1) {
                        if (shark[exist_shark_idx].size > shark[cur_idx].size) {
                            continue;
                        }else{
                            moved_board[nexty][nextx] = cur_idx;
                        }
                    }else{
                        moved_board[nexty][nextx] = cur_idx;
                    }



                }
            }
        }

        ///////////////상어 이동 끝////
        // board 업데이트
        for (int yy = 1; yy <= r; yy++) {

            for (int xx = 1; xx <= c; xx++) {
                if (moved_board[yy][xx] != -1) {
                    board[yy][xx].push_back(moved_board[yy][xx]);
                }
            }
        }



    }


    cout << sum;



    return 0;
}