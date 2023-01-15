#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[21][21];
int visited[21];
vector<int> v;
int ans = 1000000;
int total = 0;
int tmp;

void bt(int idx,int a_cnt,int b_cnt){

    if (a_cnt == n || b_cnt == n) {
        return;
    }

    if (idx >= n) {
        int sum1 = 0;
        int sum2 = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = i + 1; j < n; j++) {
                    if (visited[j]) {
                        sum1 += arr[i][j] + arr[j][i];
                    }
                }
            }else{
                for (int j = i + 1; j < n; j++) {
                    if (!visited[j]) {
                        sum2 += arr[i][j] + arr[j][i];
                    }
                }
            }
        }


        ans = min(ans, abs(sum1 - sum2));

        return;
    }

    visited[idx] = 1;
    v.push_back(idx);
    bt(idx + 1,a_cnt+1,b_cnt);
    v.pop_back();
    visited[idx] = 0;
    bt(idx + 1, a_cnt, b_cnt + 1);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> arr[y][x];
            if(y == x) continue;
            total += arr[y][x];
        }
    }

    tmp = total;

    bt(0, 0, 0);


    cout << ans;



    return 0;
}