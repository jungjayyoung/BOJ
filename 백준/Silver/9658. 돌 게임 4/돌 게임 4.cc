#include <iostream>

using namespace std;


int dp[1001];


int main(){
    
    int n;
    cin >> n;
    
    dp[1] = 0;
    dp[2] = 1; // sk가 이김
    dp[3] = 0;
    dp[4] = 1;
  
    
    for(int i = 5; i < 1001;i++){
        if(dp[i - 1] && dp[i -3] && dp[i - 4]){
            dp[i] = 0;
         }else
            dp[i] = 1;
    }
    
    if(dp[n] == 1){
        cout << "SK";
    }else
        cout << "CY";
    
    return 0;
}