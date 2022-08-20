#include <iostream>
#include <algorithm>

using namespace std;


int n;
int num[12];
int op[4];
int maxx = -1000000001;
int minn = 1000000001;
int visited[12];

void bt(int cnt,int sum){


    if(cnt == n){

        maxx = max(maxx, sum);
        minn = min(minn, sum);

        return;
    }

    for(int i = 0; i <4;i++){


        if(op[i] > 0){

            op[i]--;
            if(i == 0){
                bt(cnt+1,sum + num[cnt]);
            }else if(i == 1){
                bt(cnt+1,sum - num[cnt]);
            }else if(i == 2){
                bt(cnt+1,sum * num[cnt]);
            }else if(i ==3){
               int tmp = sum;
                bt(cnt+1,(int)(tmp / num[cnt]));
            }
            op[i]++;

        }

    }



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i=0;i <n; i++){
        cin >> num[i];
    }

    for(int i = 0; i < 4; i++){
        cin >> op[i];
    }

    bt(1, num[0]);

    cout << maxx << "\n" << minn;

    return 0;
}