#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int arr[11];
int ans[11];
int visited[11];
int n;


bool check(int idx,int num){// 현재 인덱스, 현재 인덱스에 집어넣을 숫자

    int cnt = 0;

    for (int i = 0; i < idx; i++) {
        if(ans[i] > num){
            cnt++;
        }
    }
    if(cnt == arr[num]){
        return true;
    }else
        return false;
}

void bt(int cnt){

    if (cnt == n) {

        for (int i = 0; i < cnt; i++) {
            cout << ans[i] << " ";
        }

        return;
    }

    for (int i = 1; i <= n; i++) {

        if (!visited[i]) {

            if(!check(cnt,i)) continue;
            visited[i] =  1;
            ans[cnt] = i;
            bt(cnt + 1);
            visited[i] = 0;

        }

    }

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }


    bt(0);


    return 0;
}