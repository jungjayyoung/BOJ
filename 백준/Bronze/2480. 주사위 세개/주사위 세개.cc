#include <iostream>
#include <algorithm>

using namespace std;

int visited[7];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 3; i++) {
        int num;
        cin >>num;
        visited[num]++;
    }

    int maxx = 0;
    for (int i = 1; i <= 6; i++) {
        if (visited[i] == 3) {
            cout << 10000 + i * 1000;
            return 0;
        } else if (visited[i] == 2) {
            cout << 1000 + i * 100;
            return 0;
        } else if (visited[i] == 1) {
            maxx = max(maxx, i);
        }
    }
    cout << maxx * 100;
    
    return 0;
}