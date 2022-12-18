#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

vector<string> v;
vector<string> list;
vector<string> cands; // 후보 4개가 저장된다.
int visited[1001]; // 접두사와 접미사가 같은게 있을경우 해당 길이를 1로 해준다.
int n;

bool cmp(string a,string b){
    return a.length() < b.length();
}

bool check(string c){

    vector<string> p_list;
    vector<string> s_list;

    string tmp;
    //1. prefix 리스트 만들기.
    for (int i = 0; i < c.length() - 1; i++) {
        tmp += c[i];
        p_list.push_back(tmp);
    }

    tmp = "";
    //2. suffix 리스트 만들기.
    for (int i = c.length() - 1; i >= 0; i--) {
        tmp = c[i] + tmp;
        s_list.push_back(tmp);
    }

    //3. list에 있는 입력된 모든 접두사와 접미사 집합에
    // p_list 와 s_list의 모든 값들이 존재하는지 확인하기
    int p_check[301];
    int s_check[301];

    fill(p_check, p_check + 300, 0);
    fill(s_check, s_check + 300, 0);

    for (int i = 0; i < 2 * n - 2; i++) {

        bool pcheck = false;
        bool scheck = false;
        // 접두사 중에서 체크하기
        for (int j = 0; j < p_list.size(); j++) {
            if (p_list[j] == list[i] && p_check[j] == 0) {



                p_check[j] = 1;
                pcheck = true;
            }
        }

        if(pcheck) continue;

        // 접미사 중에서 체크하기
        for (int j = 0; j < s_list.size(); j++) {

            if (s_list[j] == list[i] && s_check[j] == 0) {

                s_check[j] = 1;
                scheck = true;
            }
        }

        if(scheck) continue;

        if (!pcheck && !scheck) {
            return false;
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);



    cin >> n;


    for (int i = 0; i < 2 * n - 2; i++) {
        string str;
        cin >> str;
        v.push_back(str);
        list.push_back(str);
    }

    if (n == 2) {
        cout << v[0] << v[1] << "\n";
        cout << "PS";
        return 0;
    }

    sort(list.begin(), list.end(), cmp);

    cands.push_back(list[0] + list[list.size() - 2]);
    cands.push_back(list[0] + list[list.size() - 1]);
    cands.push_back(list[1] + list[list.size() - 2]);
    cands.push_back(list[1] + list[list.size() - 1]);

    for (int i = 0; i < 4; i++) {

        string cand = cands[i];

        if(!check(cand)) continue;

        cout << cand << "\n";
        unordered_set<string> se;
        for (int i = 0; i < 2 * n - 2; i++) {

            if (cand.find(v[i]) == 0 && se.count(v[i]) == 0) {
                cout << "P";
                se.insert(v[i]);
            }else{
                cout << "S";
            }
        }

        return 0;

    }


    return 0;
}