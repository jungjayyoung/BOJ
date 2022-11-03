#include <iostream>
#include <string>
#include <set>
#include <vector>


using namespace std;

char map[3][3];

set<string> slist;
vector<string> v;


bool check(string s){
    int xcnt = 0;
    int ocnt = 0;

    if(s[0] == 'X') {
        if (s[0] == s[1] && s[1] == s[2]) xcnt++;
        else if (s[0] == s[4] && s[4] == s[8]) xcnt++;
        else if (s[0] == s[3] && s[3] == s[6]) xcnt++;
    }
    if(s[1] == 'X'){
        if (s[1] == s[4] && s[4] == s[7]) xcnt++;
    }
    if(s[2] == 'X'){
        if (s[2] == s[5] && s[5] == s[8]) xcnt++;
        if (s[2] == s[4] && s[4] == s[6]) xcnt++;
    }

    if (s[3] == 'X') {
        if (s[3] == s[4] && s[4] == s[5]) xcnt++;
    }
    if(s[6] == 'X') {
        if (s[6] == s[7] && s[7] == s[8]) xcnt++;
    }


    if(s[0] == 'O') {
        if (s[0] == s[1] && s[1] == s[2]) ocnt++;
        else if (s[0] == s[4] && s[4] == s[8]) ocnt++;
        else if (s[0] == s[3] && s[3] == s[6]) ocnt++;
    }
    if(s[1] == 'O'){
        if (s[1] == s[4] && s[4] == s[7]) ocnt++;
    }
    if(s[2] == 'O'){
        if (s[2] == s[5] && s[5] == s[8]) ocnt++;
        if (s[2] == s[4] && s[4] == s[6]) ocnt++;
    }

    if (s[3] == 'O') {
        if (s[3] == s[4] && s[4] == s[5]) ocnt++;
    }
    if(s[6] == 'O') {
        if (s[6] == s[7] && s[7] == s[8]) ocnt++;
    }

    if (xcnt >= 1 && ocnt >= 1) {
        return false;
    } else if (xcnt >= 1 || ocnt >= 1) {
        return true;
    }

    if(s.find('.') == string::npos) {
        return true;
    }

    return false;


}

void bt(int idx, string s, int x_cnt, int o_cnt){



    if(check(s)) {

        //v.push_back(s);
        slist.insert(s);
        return;
    }

    if (idx >= 9) {


        return;
    }



    for (int i = 0; i < 9; i++) {

        //bt(idx + 1, s,x_cnt,o_cnt);

        if (idx % 2 == 0 && s[i] == '.') {
            s[i] = 'X';
            bt(idx + 1, s,x_cnt+1,o_cnt);
            s[i] = '.';
        }else if(idx %2 == 1 && s[i] == '.'){
            s[i] = 'O';
            bt(idx + 1, s,x_cnt,o_cnt + 1);
            s[i] = '.';
        }

    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    bt(0, ".........", 0, 0);

    //cout << slist.size();
//    for (auto i: slist) {
//        cout << i << "\n";
//    }

    while (1) {
        string str;

        cin >> str;

        if (str == "end") {
            break;
        }


        if (slist.find(str) != slist.end()) {
            cout << "valid" << "\n";
        }else
            cout << "invalid" << "\n";



    }


    return 0;
}