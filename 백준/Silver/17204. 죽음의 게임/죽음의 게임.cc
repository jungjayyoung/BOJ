#include <iostream>

using namespace std;


int n, k;

int arr[151];
int visited[151];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cur = 0;
    int cnt = 0;

    while (true) {
        cnt++;

        if (!visited[cur]) {
            visited[cur] = 1;
        }else
            break;

        if (arr[cur] == k) {
            cout << cnt;
            return 0;
        }

        cur = arr[cur];

    }

    cout << -1;


    return 0;
}