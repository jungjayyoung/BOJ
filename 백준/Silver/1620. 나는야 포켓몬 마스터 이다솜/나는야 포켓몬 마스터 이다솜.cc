#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


int n, m;

map<string,int> mm1;
vector<string> pock;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        mm1.insert({str, i + 1});
        pock.push_back(str);
    }
    
    for (int i = 0; i < m; i++) {
        string ss;

        cin >> ss;

        if (isdigit(ss[0])) {
            int num = stoi(ss);
            cout << pock[num-1] << "\n";
        }else{
            cout << mm1[ss] << "\n";
        }
    }
    return 0;
}