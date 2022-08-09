#include <iostream>
#include <vector>



using namespace std;

int n;
int visited[100001];
vector<int> v[100001];
int visited_num;
bool check;
bool not_group_check;
int save_idx;

void dfs(int cur,int start){


    visited[cur] = visited_num;

    int next = v[cur][0];

    if(!visited[next]){
        dfs(next,start);
    }else if (visited[next] != visited_num) {
        check = true;
    } else if (visited[next] == visited_num) {
        if (next != start) {
            save_idx = next;
        }

    }

    if(check) {
        visited[cur] = 123456789;
    }
    if (save_idx == cur) {
        not_group_check = true;
        return;
    }
    if (not_group_check) {
        visited[cur] = 123456789;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--) {
        fill(visited, visited + n + 1, 0);


        visited_num = 1;
        int ans = 0;
        cin >> n;

        // 서로 원하는 짝 정하기
        for (int i = 1; i <= n; i++) {

            int num;
            cin >> num;
            v[i].push_back(num);
            if (i == num) {
                visited[i] =visited_num++;
            }

        }

        for (int i = 1; i <= n; i++) {
            check = false;
            save_idx = -1;
            not_group_check = false;

            if (visited[i] == 0) {
                dfs(i,i);
                if (!check) {
                    visited_num++;
                }
            }

        }
        for (int i = 1; i <= n; i++) {

            if (visited[i] == 123456789 || visited[i] == 0) {
                ans++;
            }
        }


        cout << ans << "\n";

        for (int i = 1; i <= n; i++) {
            v[i].clear();
        }

    }




    return 0;
}