#include <iostream>


using namespace std;


int paper[7];
int visited[7][7];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    for (int i = 1; i <= 6; i++) {
        cin >> paper[i];
    }

    // 제일 큰 것부터 붙인다.

    bool paper_check = false;
    int cnt = 1;
    int cur_size = 6;


    while (true) {

        paper_check = false;

        for (int i = 1; i <= 6; i++) {
            if(paper[i] > 0) {
                paper_check = true;
            }
        }

        // 더이상 색종이가 없으면 탈출
        if (!paper_check) {
            break;
        }

        bool next_paper = false; // 종이가 색종이로 꽉찼으면 false

        for (int y = 0; y < 6; y++) {

            for (int x = 0; x < 6; x++) {
                int sx = x;
                int sy = y;

                if (paper[cur_size] <= 0) {
                    break;
                }

                if(sx + cur_size > 6 || sy + cur_size > 6) continue;
                bool check2 = false; // 현재 영역에 방문 불가능 구역이 있으면 true가 된다.

                for (int xx = sx; xx < sx + cur_size; xx++) {

                    for (int yy = sy; yy < sy + cur_size; yy++) {

                        if (visited[yy][xx]) {
                            check2 = true;
                            break;
                        }


                    }
                    if (check2) {
                        break;
                    }

                }

                // 현재 구역과 맞는 색종이가 있으면 visited를 1로 만들어준다.
                if (!check2) {
                    next_paper = true;
                    paper[cur_size]--;
                    for (int xx = sx; xx < sx + cur_size; xx++) {

                        for (int yy = sy; yy < sy + cur_size; yy++) {
                            visited[yy][xx] = 1;
                        }
                    }
                }
            }

            if (paper[cur_size] <= 0) {
                break;
            }

        }


        //현재 크기의 색종이가 없거나 새로운 종이가 필요하면 색종이의 크기를 하나 줄인다.
        if (paper[cur_size] <= 0 || !next_paper) {
            cur_size--;

            // 크기가 1인 색종이까지 검사완료
            if(cur_size == 0) {

                // 만약에 종이가 꽉 찼다면 visited배열을 초기화 시키고 다음 종이를 준다

                if(!next_paper) {
                    fill(&visited[0][0], &visited[6][0], 0);
                    cnt++;
                }
                cur_size = 6;

            }
        }

    }

    cout << cnt;


    return 0;
}