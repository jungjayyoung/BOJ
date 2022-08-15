#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> v;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    cout << v[(v.size() - 1) / 2];


    return 0;
}