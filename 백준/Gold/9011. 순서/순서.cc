#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
int rarr[101];
int sarr[101];
int visited[101];
bool check = false;

void bt(int idx){

    if (idx <= -1) {

        for (int i = 0; i < n; i++) {
            cout << sarr[i] << " ";
        }
        cout << "\n";
        check = true;
        return;
    }

    for (int i = n; i > rarr[idx]; i--) {

        if (!visited[i]) {
            int cnt = 0;
            for (int j = 1; j < i; j++) {
                if(!visited[j]) {
                    cnt++;
                }
            }
            if (cnt != rarr[idx]) continue;
            visited[i] = 1;
            sarr[idx] = i;
            bt(idx - 1);
            if(check) return;
            visited[i] = 0;
        }

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> rarr[i];
        }

        check = false;
        fill(visited, visited + n + 1, 0);

        bt(n - 1);

        if(!check) {
            cout << "IMPOSSIBLE" << "\n";
        }

    }


    return 0;
}