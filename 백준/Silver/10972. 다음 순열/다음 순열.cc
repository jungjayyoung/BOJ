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
    if(next_permutation(v.begin(),v.end())){
        for (auto i: v) {
            cout << i << " ";
        }
    }else{
        cout << -1;
    }
    return 0;
}