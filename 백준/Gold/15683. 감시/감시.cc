#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ARR_SIZE 9
using namespace std;

int n,m;
char board[9][9];
char ans_board[9][9];
int visited[9][9];
int min_zero = 9876;
int tt = 0;
queue<pair<int,int>> cam_five;

vector<pair<pair<int,int>,int>> cam;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void show(){

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cout << ans_board[y][x] << " ";
        }
        cout << "\n";
    }


}

int zero_cnt(){

    int num = 0;
    for (int y = 0; y < n; y++) {

        for (int x = 0; x < m; x++) {

            if (board[y][x] == '0') {
                num++;
            }
        }
    }
    return num;

}

//idx 번째 카메라 회전
void rotate_four(int x,int y,int dir){


    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if(i == dir) continue; //현재 방향은 뺀다.

        while (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n) {
            if (board[nexty][nextx] == '6') break;

            if(board[nexty][nextx] == '0') {
                board[nexty][nextx] = '#';
            }
            nextx = nextx + dx[i];
            nexty = nexty + dy[i];
        }

    }

}

void rotate_three(int x,int y,int dir){



    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        //int dx[4] = {-1, 0, 1, 0};
        //int dy[4] = {0, 1, 0, -1};
        if(dir == 0){
            if(i == 0 || i ==3) continue;
        } else if (dir == 1) {
            if(i == 0 || i ==1) continue;
        } else if (dir == 2) {
            if(i == 1 || i ==2) continue;
        } else if (dir == 3) {
            if(i == 2 || i ==3) continue;
        }

        while (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n) {
            if (board[nexty][nextx] == '6') break;

            if(board[nexty][nextx] == '0') {
                board[nexty][nextx] = '#';
            }
            nextx = nextx + dx[i];
            nexty = nexty + dy[i];
        }

    }

}

void rotate_two(int x, int y, int dir) {


    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if (dir == 0) {
            if (i == 0 || i == 2) continue;
        } else if (dir == 1) {
            if (i == 1 || i == 3) continue;
        }

        while (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n) {
            if (board[nexty][nextx] == '6') break;

            if (board[nexty][nextx] == '0') {
                board[nexty][nextx] = '#';
            }
            nextx = nextx + dx[i];
            nexty = nexty + dy[i];
        }

    }

}

void rotate_one(int x,int y, int dir){



    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if(i != dir) continue; //현재 방향은 뺀다.

        while (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n) {
            if (board[nexty][nextx] == '6') break;

            if(board[nexty][nextx] == '0') {
                board[nexty][nextx] = '#';
            }
            nextx = nextx + dx[i];
            nexty = nexty + dy[i];
        }

    }

}




void bt(int cnt){

    if (cnt >= cam.size()) {

        int num = zero_cnt();

        min_zero = min(min_zero, num);
        copy(&board[0][0], &board[0][0] + ARR_SIZE * ARR_SIZE, &ans_board[0][0]);

        return;
    }

    char copy_board[ARR_SIZE][ARR_SIZE]; // 초기 보드판 상태
    copy(&board[0][0], &board[0][0] + ARR_SIZE * ARR_SIZE, &copy_board[0][0]);


    for (int i = 0; i < cam.size(); i++) {

        if (cnt != i) continue;


        int cur_cam_num = cam[i].second;
        int cur_cam_x = cam[i].first.first;
        int cur_cam_y = cam[i].first.second;

        if (cur_cam_num == 4 || cur_cam_num == 3 || cur_cam_num == 1) {
            for (int j = 0; j < 4; j++) {
                //초기 보드판 상태로 초기화
                copy(&copy_board[0][0], &copy_board[0][0] + ARR_SIZE * ARR_SIZE, &board[0][0]);

                if (cur_cam_num == 4) {
                    rotate_four(cur_cam_x, cur_cam_y, j);
                } else if (cur_cam_num == 3) {
                    rotate_three(cur_cam_x, cur_cam_y, j);
                } else if (cur_cam_num == 1) {
                    rotate_one(cur_cam_x, cur_cam_y, j);
                }
                bt(cnt + 1);

            }
        } else if (cur_cam_num == 2) {
            for (int j = 0; j < 2; j++) {
                //초기 보드판 상태로 초기화
                copy(&copy_board[0][0], &copy_board[0][0] + ARR_SIZE * ARR_SIZE, &board[0][0]);

                rotate_two(cur_cam_x, cur_cam_y, j);
                bt(cnt + 1);

            }
        }




    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;


    for (int y = 0; y < n; y++) {

        for (int x = 0; x < m; x++) {

            cin >> board[y][x];
            if (board[y][x] == '1') {
                cam.push_back({{x,y},1});
            } else if (board[y][x] == '2') {
                cam.push_back({{x,y},2});
            }else if (board[y][x] == '3') {
                cam.push_back({{x,y},3});
            }else if (board[y][x] == '4') {
                cam.push_back({{x,y},4});
            }else if (board[y][x] == '5') {
                cam_five.push({x, y});
            }
        }
    }

    //만약에 5번 카메라가 존재한다면 5번 카메라는 방향이 존재하지 않으므로 먼저 감시 영역을 설정해주자
    while (!cam_five.empty()) {

        int cur_five_x = cam_five.front().first;
        int cur_five_y = cam_five.front().second;

        cam_five.pop();

        //상하좌우 감시 지대 설정
        for (int i = 0; i < 4; i++) {
            int nextx = cur_five_x + dx[i];
            int nexty = cur_five_y + dy[i];

            while(nextx >= 0 && nextx < m && nexty >= 0 && nexty < n){

                if (board[nexty][nextx] == '6') break;

                if(board[nexty][nextx] == '0') {
                    board[nexty][nextx] = '#';
                }


                nextx = nextx + dx[i];
                nexty = nexty + dy[i];
            }

        }


    }

    bt(0);

    //show();
    cout << min_zero;


    return 0;
}
