#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;


int arr[11];
int visited[11];
int n;
int ans = 0;
vector<int> v;

void bt(int cnt,int sum){

    if (cnt == 2) {


        ans = max(ans, sum);

        return;
    }

    for (int i = 1; i < v.size()- 1; i++) {
        int a1 = v[i - 1];
        int a2 = v[i + 1];
        int tmp = v[i];
        v.erase(v.begin() + i);
        bt(cnt - 1, sum + (a1 * a2));
        v.insert(v.begin() + i, tmp);
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }

    bt(n, 0);

    cout << ans;

    return 0;
}