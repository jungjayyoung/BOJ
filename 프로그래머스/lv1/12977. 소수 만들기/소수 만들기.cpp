#include <vector>
#include <iostream>
using namespace std;
int visited[51];
bool not_prime[500000] ={1,1,0};
vector<int> v;
vector<int> chosen;
int answer = 0;

void solve(){
    
    for(int i=2; i<=500000;i++){
        
        if(not_prime[i] == 0){
            for(int j = 2*i;j<=500000; j+=i){
                not_prime[j] = 1;
            }
        
        }
        
        
    }
}

void bt(int idx, int cnt){
    

    if(cnt >= 3){
        
        int sum = 0;
        for(int i=0;i<chosen.size();i++){
            sum += chosen[i];
        }
        
        if(!not_prime[sum]){
            answer++;
        }
        
        return;
    }
    
    
    for(int i=0;i<v.size();i++){
        
        if(idx > i) continue;
        
        if(!visited[i]){
            visited[i] = 1;
            chosen.push_back(v[i]);
            bt(i,cnt+1);
            chosen.pop_back();
            visited[i] = 0;
        }
    }
    
    
}

int solution(vector<int> nums) {
    
    solve();

    v = nums;
    

    bt(0,0);

    return answer;
}