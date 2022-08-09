#include <iostream>
#include <string>


using namespace std;


int num2[6] ={1,2,3,5,7,9};
int n;
int ans[9];

bool prime(int num){

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;

}
void bt(int num, int cnt){

    if (cnt == n) {

        cout << num;
        cout << "\n";
        return;
    }


    for (int i = 0; i < 6; i++) {

        if (cnt == 0 && (i == 0 || i == 5)) {
            continue;
        }
        if (cnt > 0 && (i == 1 || i == 3)) {
            continue;
        }

        if(prime(num * 10 + num2[i]))
            bt(num * 10 + num2[i], cnt + 1);


    }



}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);



    cin >> n;


    bt(2, 1);
    bt(3, 1);
    bt(5, 1);
    bt(7, 1);

    return 0;
}