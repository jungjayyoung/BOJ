#include <string>
#include <vector>
#include <queue>

using namespace std;

int level_cnt[10];
queue<pair<int,int>> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    for(int i=0; i< priorities.size();i++){
        q.push({priorities[i],i});
        level_cnt[priorities[i]]++;
    }
    
    int cnt = 1;
    
    while(!q.empty()){
        
        int selected_level;
        
        for(int i = 9; i>= 1; i--){
            
            if(level_cnt[i] >= 1){
                level_cnt[i]--;
                selected_level = i;
                break;
            }
            
        }
        
        while(q.front().first != selected_level){
            pair<int,int> tmp = q.front();
            q.push(tmp);
            q.pop();
        }
        
        if(q.front().second == location){
            break;
        }
        
        q.pop();
        cnt++;
        
    }
    
    return cnt;
}