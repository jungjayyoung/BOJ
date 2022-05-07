#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int tree[10001];
string trees[10001];
string str[1000001];
double per[10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);



    int cnt=0;
    string tmp;
    while (1){

        getline(cin, tmp);
        if(cin.eof()) break;
        //if(tmp == "1") break;
        str[cnt] = tmp;
        cnt++;
    }

    sort(str, str + cnt);


    int start = 0;
    int idx = 0;
    trees[start] = str[0];
    for (int i = 0; i <= cnt; i++) {
        if (str[i] == str[idx]) {
            tree[start]++;
        }else{
            start++;
            tree[start]++;
            trees[start] = str[i];
            idx = i;
        }
    }
    int total = cnt;

    for (int i = 0; i < start; i++) {
        per[i] = tree[i] * 100 / (double)total;
    }




    cout.precision(4);
    cout << fixed;

    for (int i = 0; i < start; i++) {
        cout << trees[i] << " " << per[i] << "\n";
    }
    return 0;
}