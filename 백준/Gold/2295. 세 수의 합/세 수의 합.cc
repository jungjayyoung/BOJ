#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (int i = n - 1; i >= 0; i--) {

        // k의 값을 미리 정한다.
        int k = v[i];

        for (int x = n - 1; x >= 0; x--) {
            for (int y = n - 1; y >= 0; y--) {
                //두 수의 합이 goal보다 크면 continue한다.
                if (v[x] + v[y] > k) continue;

                for (int z = n - 1; z >= 0; z--) {
                    int sum = v[x] + v[y] + v[z];
                    //세 수의 합이 goal보다 크면 continue한다.
                    if (sum > k) {
                        continue;
                    }
                    if (sum == k) {
                        cout << k;
                        return 0;
                    }

                }

            }
        }

    }


    return 0;
}

