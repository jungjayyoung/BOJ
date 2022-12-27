#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string,string> mm;
int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        mm.insert({a, b});
    }

    for (int i = 0; i < m; i++) {
        string a;
        cin >> a;
        cout << mm[a] << "\n";
    }



    return 0;
}