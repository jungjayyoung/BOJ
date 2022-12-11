#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> origin;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        origin.push_back(num);
    }

    sort(v.begin(), v.end());

    if (v == origin) {
        cout << -1;
        return 0;
    }

    int cnt = 0;
    do {

        if (cnt == 1) {
            for (int i = 0; i < origin.size(); i++) {
                cout << origin[i] << " ";
            }
            return 0;
        }
        cnt++;

    } while (prev_permutation(origin.begin(), origin.end()));


}