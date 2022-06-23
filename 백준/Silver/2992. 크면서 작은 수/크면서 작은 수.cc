#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> v;
string num;
int visited[7];
int ans = 1000000;
int a;

void bt(string ss, int size){

    if (size >= num.size()) {
        if (ss[0] == 0) {
            return;
        }
        int tmp = stoi(ss);

        if(tmp > a){
            ans = min(ans, tmp);
        }

        return;
    }


    for (int i = 0; i < v.size(); i++) {

        if (!visited[i]) {
            visited[i] = 1;
            bt(ss + v[i], size + 1);
            visited[i] = 0;
        }

    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> num;

    for (int i = 0; i < num.size(); i++) {
        v.push_back(num[i]);
    }

    a = stoi(num);

    bt("", 0);

    if(ans == 1000000){
        cout << 0;
    }else
        cout << ans;



    return 0;
}