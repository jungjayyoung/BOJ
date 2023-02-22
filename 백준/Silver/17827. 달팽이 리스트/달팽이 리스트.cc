#include <iostream>


using namespace std;

int n, m, v;

int arr[200001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> v;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // 사이클이 시작하는 노드 번호
    int start = v;

    for (int i = 0; i < m; i++) {

        int q;
        cin >> q;

        if (q < n) {
            cout << arr[q + 1];
        } else {

            q = (q - (v - 1)) % (n - (v - 1));
            q += v;
            cout << arr[q];
        }

        cout << "\n";


    }


    return 0;
}