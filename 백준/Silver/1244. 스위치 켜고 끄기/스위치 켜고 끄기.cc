#include <iostream>



using namespace std;

int arr[101];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int t;
    cin >> t;

    for (int k = 0; k < t; k++) {
        int a, b;
        cin >> a >> b;

        if (a == 1) {

            for (int j = 1; j <= n; j++) {
                if (j % b == 0) {
                    if (arr[j] == 1) {
                        arr[j] = 0;
                    }else{
                        arr[j] = 1;
                    }
                }
            }

        } else if (a == 2) {
            int start = b;
            int end = b;

            while (start - 1 >= 1 && end + 1 <= n) {
                if (arr[start - 1] == arr[end + 1]) {
                    start = start - 1;
                    end = end + 1;
                }else
                    break;
            }

            for (int i = start; i <= end; i++) {
                if (arr[i] == 1) {
                    arr[i] = 0;
                }else
                    arr[i] = 1;
            }

        }

    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
        if (i % 20 == 0) {
            cout << "\n";
        }
    }

    return 0;
}