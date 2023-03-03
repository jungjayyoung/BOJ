#include <iostream>
#include <algorithm>


using namespace std;

int n;
int visited[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;


    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        int num;
        cin >> num;
        if (!visited[num]) {
            visited[num] = 1;
            cnt++;
        } else if (visited[num]) {
            visited[num] = 0;
            cnt--;
        }
        ans = max(ans, cnt);
    }


    cout << ans;


    return 0;
}