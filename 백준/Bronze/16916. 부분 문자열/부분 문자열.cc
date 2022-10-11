#include <iostream>
#include <string>


using namespace std;
typedef long long ll;

// 롤링 해쉬로 풀기
// x는 27로 풀자 type은 무조건 long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string s1;
    string s2;
    ll p =1;
    ll x= 27;
    ll hash =0; // 부분 문자열의 hash 값
    ll num = 0; // 부분 문자열 존재 여부를 판단할 hash 저장소

    cin >> s1 >> s2;
    
    if(s2.size() > s1.size()){
        cout << 0;
        return 0;
    }

    // 1. 부분 문자열 hash 값 구하기
    for(int i=s2.size() - 1; i >= 0;i--){
        hash += ll(s2[i] - 'a' + 1) * p;
        p = p * x;
    }

    // 2. 전체 문자열의 첫번째 부분문자열부터 hash 값 구하기

    p = 1;
    for(int i = s2.size() - 1; i>=0; i--){
        num += ll(s1[i] - 'a' + 1) * p;
        p = p * x;
    }

    if(hash == num){
        cout << 1;
        return 0;
    }

    p /= x;

    for(int i = 0; i< s1.size() - s2.size();i++){
        num -= ll(s1[i] - 'a' + 1) * p;
        num *= x;
        num += ll(s1[i + s2.size()] - 'a' + 1);
        if(hash == num){
            cout << 1;
            return 0;
        }

    }

    cout << 0;





    return 0;
}