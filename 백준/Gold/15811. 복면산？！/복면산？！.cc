#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

string a,b,c;



int alp_visited[27]; // 서로 다른 알파벳을 저장할 때 사용할 visited 배열
vector<char> alp; // 서로 다른 알파벳을 저장할 벡터
bool check = false;

// 백트래킹에 사용할 변수들
int visited[10]; // 숫자 visited 배열

int str1 = 0;
int str2 = 0;
int str3 = 0;
int a_sum[27];
int b_sum[27];
int c_sum[27];
void bt(int cnt){

    if (cnt == alp.size()) {


        if (str1 + str2 == str3) {
            check = true;
        }

        return;

    }

    for (int i = 0; i <= 9; i++) {

        if(check) return;
        if (!visited[i]) {
            visited[i] = 1;

            str1 += a_sum[alp[cnt] - 'A'] * i;
            str2 += b_sum[alp[cnt] - 'A'] * i;
            str3 += c_sum[alp[cnt] - 'A'] * i;
            bt(cnt + 1);

            str1 -= a_sum[alp[cnt] - 'A'] * i;
            str2 -= b_sum[alp[cnt] - 'A'] * i;
            str3 -= c_sum[alp[cnt] - 'A'] * i;
            visited[i] = 0;
        }
    }

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> c;

    //1. 서로 다른 알파벳은 최대 10개 존재할 수 있다. 숫자는 0~9 이므로
    //   서로 다른 알파벳이 총 몇 개가 존재하는지 어딘가에 담아두고 백트래킹 할 때 그 크기에 해당하면 리턴하도록 만든다.

    // 첫번째 단어에서 알파벳 고르기
    for (int i = 0; i < a.size(); i++) {
        if (!alp_visited[a[i] - 'A']) {
            alp_visited[a[i] - 'A'] = 1;
            alp.push_back(a[i]);
        }
    }

    // 두번째 단어에서 알파벳 고르기
    for (int i = 0; i < b.size(); i++) {
        if (!alp_visited[b[i] - 'A']) {
            alp_visited[b[i] - 'A'] = 1;
            alp.push_back(b[i]);
        }
    }

    //세번째 단어에서 알파벳 고르기
    for (int i = 0; i < c.size(); i++) {
        if (!alp_visited[c[i] - 'A']) {
            alp_visited[c[i] - 'A'] = 1;
            alp.push_back(c[i]);
        }
    }

    // 0~9의 숫자를 할당할 알파벳이 벡터 alp에 담겨져 있다. 최대 10개가 존재한다.
    // 순열을 구하는 것이므로 최악의 경우 10!의 시간복잡도가 걸린다.
    // 백트래킹으로 구할 수 있다!

    // 각 a,b,c 문자열의 26개의 알파벳의 자릿수의 합을 a[27], b[27],c[27] 에 저장한다.
    // 예를 들어 문자열 a가 SUS인 경우 a_sum[S]: 101, a_sum[U]: 10 이렇게 저장이 된다.

    for (int i = 0; i < a.size(); i++) {
        a_sum[a[i] - 'A'] += (int)pow(10, a.size() - i - 1);
    }


    for (int i = 0; i < b.size(); i++) {
        b_sum[b[i] - 'A'] += (int)pow(10, b.size() - i - 1);
    }

    for (int i = 0; i < c.size(); i++) {
        c_sum[c[i] - 'A'] += (int)pow(10, c.size() - i - 1);
    }



    bt(0);


    if (check) {
        cout << "YES";
    }else
        cout << "NO";


    return 0;
}