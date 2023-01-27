#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<int> v;
vector<int> vv;

bool check(int n1, int n2){

    if(n1 % n2 == 0) return true;
    return false;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }



    sort(v.begin(), v.end());

    for (int i = 1; i < v.size(); i++) {
        vv.push_back(v[i] - v[i - 1]);
    }

    sort(vv.begin(), vv.end());

    int minn = vv[0];

    for (int i = 0; i < n - 1; i++) {

        if ( !check(vv[i], minn)) {
            minn--;
            i = -1;
        }

    }

    cout << ((v[n - 1] - v[0]) / minn + 1) - n;




    return 0;
}