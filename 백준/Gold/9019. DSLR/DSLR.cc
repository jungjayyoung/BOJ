#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int visited[10001];
int parent[10001];

vector<int> path;

int a, b;


void bfs(){

    queue<int> q;
    q.push(a);
    visited[a] = 1;

    while(!q.empty()){

        int cur_num = q.front();


        q.pop();

        if (cur_num == b) {
            while(cur_num != a){
                path.push_back(cur_num);
                cur_num = parent[cur_num];
            }
            path.push_back(a);
            return;
        }

        //1. 두 배로 바꾸기 9999보다 크면 10000으로 나눈 나머지
        if(!visited[(cur_num * 2) % 10000]){
            q.push((cur_num * 2) % 10000);
            visited[(cur_num * 2) % 10000] = 1;
            parent[(cur_num * 2) % 10000] = cur_num;
        }

        //2. 1을 빼기 만약에 cur_num 이 0 이라면 9999가 된다.
        int tmp = cur_num - 1;
        if (tmp < 0) {
            tmp = 9999;
        }
        if (!visited[tmp]) {
            q.push(tmp);
            visited[tmp] = 1;
            parent[tmp] = cur_num;
        }

        // 3. 각 자리 수를 왼쪽으로 회전
        int f1 = cur_num / 1000;
        int f2 = cur_num % 1000;
        tmp = (f2 * 10) + f1;
        if (!visited[tmp]) {
            q.push(tmp);
            visited[tmp] = 1;
            parent[tmp] = cur_num;
        }

        //4. 각 자리 수를 오른쪽으로 회전
        f1 = cur_num / 10;
        f2 = cur_num % 10;
        tmp = (f2 * 1000) + f1;
        if (!visited[tmp]) {
            q.push(tmp);
            visited[tmp] = 1;
            parent[tmp] = cur_num;
        }

    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--) {

        cin >> a >> b;
        fill(visited, visited + 10000, 0);


        bfs();

        int cur_num = path[path.size() - 1];
        int next_num;

        for (int i = path.size() - 2; i >= 0; i--) {
            next_num = path[i];
            bool check = false;

            // D
            if((cur_num * 2) % 10000 == next_num && !check){
                cout << "D";
                check = true;

            }

            // S
            int tmp = cur_num - 1;
            if (tmp < 0) {
                tmp = 9999;
            }

            if (tmp == next_num && !check) {
                cout << "S";
                check = true;
            }

            // L
            int f1 = cur_num / 1000;
            int f2 = cur_num % 1000;
            tmp = (f2 * 10) + f1;

            if (tmp == next_num && !check) {
                cout << "L";
                check = true;
            }

            // R
            f1 = cur_num / 10;
            f2 = cur_num % 10;
            tmp = (f2 * 1000) + f1;

            if (tmp == next_num && !check) {
                cout << "R";
                check = true;
            }

            cur_num = next_num;

        }

        cout << "\n";
        path.clear();
    }


    return 0;
}