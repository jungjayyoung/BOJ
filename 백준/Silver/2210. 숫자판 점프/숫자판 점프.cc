#include <iostream>
#include <set>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int map[5][5];
set<string> st;

void dfs(int x, int y,int cnt,string str){


    if (cnt >= 5) {

        st.insert(str);

        return;
    }


    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx <0 || ny < 0 || nx >= 5 || ny >= 5) continue;

        dfs(nx, ny, cnt + 1, str + to_string(map[ny][nx]));

    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            cin >> map[y][x];
        }
    }

    for (int y = 0; y < 5; y++) {

        for (int x = 0; x < 5; x++) {

            dfs(x, y, 0, to_string(map[y][x]));

        }

    }

    cout << st.size();

    return 0;
}