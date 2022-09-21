#include <iostream>

using namespace std;
int visited[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=10000;i++){
        int sum = i;
        int j = i;

        while(j != 0){
            sum += j % 10;
            j = j / 10;

        }
        if(sum < 10001){
            visited[sum] = 1;
        }


    }

    for(int i=1;i<=10000;i++){

        if(visited[i] == 0)

            cout << i << "\n";

    }



    return 0;
}