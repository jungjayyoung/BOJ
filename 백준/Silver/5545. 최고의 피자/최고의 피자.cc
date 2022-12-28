#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n, a, b, dough;
vector<int> toping;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a >> b;

    cin >> dough;

    for (int i = 0; i < n; i++) {
        int aa;
        cin >> aa;
        toping.push_back(aa);
    }

    sort(toping.begin(), toping.end(), greater<>());

    int ans = dough / a;
    int sum = dough;

    for (int i = 0; i < n; i++) {

        sum += toping[i];

        if (sum / (a + b * (i + 1)) > ans) {
            ans = sum / (a + b * (i + 1));
        }

    }

    cout << ans;


    return 0;
}