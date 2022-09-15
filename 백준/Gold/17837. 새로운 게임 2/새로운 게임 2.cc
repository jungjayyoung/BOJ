#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n,k;

int board_color[13][13];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
deque<int> board[13][13]; // 몇 번 말인지, 해당 칸에서 몇번째에 있는지

vector<pair<pair<int,int>,int>> mal;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> k;


    // 체스 판 0: 흰색 1: 빨간색 2: 파란색
    // 한 칸에 말이 4개 이상인 경우 게임이 종효된다.
    for (int y = 1; y <= n; y++) {

        for (int x = 1; x <= n; x++) {
            cin >> board_color[y][x];
        }
    }

    // 덱을 사용해서 해당 칸에 쌓인 말들의 인덱스를 보여준다.
    // 덱의 맨 앞이 맨 아래에 해당한다.
    // 말의 인덱스는 0부터 시작한다.
    // 말의 좌표는 1,1 부터 시작한다.
    for (int i = 0; i < k; i++) {
        int a,b,c;
        cin >> a >> b >> c;

        mal.push_back({{a, b}, c}); // 몇번 말, 방향 (1,2,3,4)
        board[a][b].push_back(i);

    }

    int turn = 1;

    while(true){

        if (turn > 1000) {
            break;
        }

        //0째 말부터 순서대로

        bool check2 = false;

        for (int i = 0; i < k; i++) {

            int cur_x = mal[i].first.second;
            int cur_y = mal[i].first.first;
            int cur_dir = mal[i].second;

            int nextx = cur_x + dx[cur_dir - 1];
            int nexty = cur_y + dy[cur_dir - 1];
            
            // 다음 칸이 파란 색일 때
            // 파란색인 경우에는 해당 말의 방향을 반대로 바꿔주고
            // cur_dir, nextx,nexty 도 갱신해준다.
            if (nextx < 1 || nexty < 1 || nextx > n || nexty > n || board_color[nexty][nextx] == 2) {
                check2 = true;
                if(cur_dir == 1){
                    mal[i].second = 2;
                    cur_dir = 2;
                    nextx = cur_x + dx[cur_dir - 1];
                    nexty = cur_y + dy[cur_dir - 1];
                } else if (cur_dir == 2) {
                    mal[i].second = 1;
                    cur_dir = 1;
                    nextx = cur_x + dx[cur_dir - 1];
                    nexty = cur_y + dy[cur_dir - 1];
                } else if (cur_dir == 3) {
                    mal[i].second = 4;
                    cur_dir = 4;
                    nextx = cur_x + dx[cur_dir - 1];
                    nexty = cur_y + dy[cur_dir - 1];
                } else if (cur_dir == 4) {
                    mal[i].second = 3;
                    cur_dir = 3;
                    nextx = cur_x + dx[cur_dir - 1];
                    nexty = cur_y + dy[cur_dir - 1];
                }

            }

            if(check2){

                if (nextx < 1 || nexty < 1 || nextx > n || nexty > n || board_color[nexty][nextx] == 2) continue;
                check2 = false;
            }
            
            if(board_color[nexty][nextx] == 0){ // 흰색일 때
                // 먼저 i번 말이 있는 칸에 다른 말들이 있는지 체크
                int cnt = 0;

                // 다른 말이 있으면 맨 앞이 i번 말일 때까지 앞에서 pop하고 뒤에 push한다.
                if (board[cur_y][cur_x].size() != 1) {
                    while (board[cur_y][cur_x].front() != i) {
                        int tmp = board[cur_y][cur_x].front();
                        board[cur_y][cur_x].pop_front();
                        board[cur_y][cur_x].push_back(tmp);
                        cnt++;
                    }
                }

                // i번쨰가 맨 앞이면 (전체사이즈 - cnt) 만큼 앞에 있는 말들을 다음 칸 뒤에 push 해준다.
                // 동시에 해당 말의 x,y 위치를 바꿔준다.
                int deque_size = board[cur_y][cur_x].size();
                for (int j = 0; j < deque_size - cnt; j++) {
                    int tmp = board[cur_y][cur_x].front();
                    board[nexty][nextx].push_back(tmp);
                    mal[tmp].first.first = nexty;
                    mal[tmp].first.second = nextx;
                    board[cur_y][cur_x].pop_front();
                }

            }else if(board_color[nexty][nextx] == 1){ // 빨간색일 때

                //덱의 맨 뒤가 i번 말일 때까지 pop하면서 다음 칸 뒤에 push 해준다
                // 동시에 해당 말의 x,y 위치를 바꿔준다.
                // i 번 말은 while 문 밖에서 해준다.
                while (board[cur_y][cur_x].back() != i) {
                    int tmp = board[cur_y][cur_x].back();
                    board[nexty][nextx].push_back(tmp);
                    mal[tmp].first.first = nexty;
                    mal[tmp].first.second = nextx;
                    board[cur_y][cur_x].pop_back();
                }

                // i번 말을 다음 칸으로 이동
                board[nexty][nextx].push_back(board[cur_y][cur_x].back());
                mal[board[cur_y][cur_x].back()].first.first = nexty;
                mal[board[cur_y][cur_x].back()].first.second = nextx;
                board[cur_y][cur_x].pop_back();

            }

            if (board[nexty][nextx].size() >= 4) {
                cout << turn;
                exit(0);
            }

        }
        turn++;

    }

    cout << -1;


    return 0;
}