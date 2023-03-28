#include <iostream>
#include <string>


using namespace std;


int map[9][9];
int n;
int nx, ny;

// 다음 위치를 계산해준다.
void cal(int x,int y,string str){


    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'R') {
            x = x + 1;
        }else if(str[i] == 'L'){
            x = x - 1;
        } else if (str[i] == 'B') {
            y = y - 1;
        } else if (str[i] == 'T') {
            y = y + 1;
        }
    }
    nx = x;
    ny = y;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    string s1, s2;

    // 알파벳은 x, 숫자는 y 위치
    cin >> s1 >> s2 >> n;

    map[s1[1] - '0'][s1[0] - 'A' + 1] = 1; // 1은 킹 위치
    map[s2[1] - '0'][s2[0] - 'A' + 1] = 2; // 2은 돌 위치

    // kx, ky, sx, sy 위치는 계속 업데이트 된다.
    //처음 킹 위치
    int kx = s1[0] - 'A' + 1;
    int ky = s1[1] - '0'; // 1부터 8 만 나오기 때문에 1을 더하지 않는다.

    // 처음 돌 위치
    int sx = s2[0] - 'A' + 1;
    int sy = s2[1] - '0';

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        cal(kx, ky, str);

        // 킹의 다음 위치 : nx,ny
        // 킹이 떨어지면 continue;
        if (nx < 1 || ny < 1 || nx > 8 || ny > 8) continue;
        // 킹의 다음 위치에 돌이 있다면
        if(map[ny][nx] == 2){
            int tmpx = nx;
            int tmpy = ny;
            cal(sx, sy, str);

            // 돌이 떨어지면 continue;
            if (nx < 1 || ny < 1 || nx > 8 || ny > 8) continue;
            // 모든 조건을 만족하면 돌과 킹의 위치 업데이트
            map[ky][kx] = 0;
            kx = tmpx;
            ky = tmpy;
            map[tmpy][tmpx] = 1;
            sx = nx;
            sy = ny;
            map[sy][sx] = 2;

        }else{
            // 킹의 위치만 변경된다.
            map[ky][kx] = 0;
            kx = nx;
            ky = ny;
            map[ny][nx] = 1;
        }


    }

    cout << (char) (kx - 1 + 'A') << (char) (ky + '0') << "\n";
    cout << (char) (sx - 1 + 'A') << (char) (sy + '0');



    return 0;
}