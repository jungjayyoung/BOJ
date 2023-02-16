#include <iostream>
#include <string>

using namespace std;

string h, n;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> n;

    int start = 0;
    int pos;
    int cnt = 0;

    while (pos != string::npos) {

        pos = h.find(n, start);
        start = pos + 1;
        if(pos == string::npos) break;
        cnt++;

    }

    cout << cnt;
    return 0;
}
