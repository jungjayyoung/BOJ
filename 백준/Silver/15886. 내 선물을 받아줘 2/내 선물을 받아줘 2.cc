#include <iostream>
#include <string>

using namespace std;

int visited[1001];
string s;
int ans = 0;
bool check = false;
void dfs(int cur,int visit_num){


    visited[cur] = visit_num;

    if(s[cur] == 'E'){

        if(cur + 1 >= s.size()) {
            return;
        }else{

            if (!visited[cur + 1]) {
                dfs(cur + 1, visit_num);
            } else if (visited[cur + 1] != visit_num) {
                check = true;
                return;
            }


        }

    } else if (s[cur] == 'W') {
        if(cur - 1 < 0){
            return;
        }else{
            if (!visited[cur - 1]) {
                dfs(cur - 1, visit_num);
            } else if (visited[cur - 1] != visit_num) {
                check = true;
                return;
            }
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);



    int n;
    cin >> n;
    cin >> s;


    int cnt = 1;
    for (int i = 0; i < s.size(); i++) {

        if(!visited[i]){
            check = false;
            dfs(i, cnt);
            cnt++;
            if(!check){
                ans++;
            }
        }
    }
    
    cout << ans;

    return 0;
}