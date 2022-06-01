#include <string>
#include <vector>
#include <queue>


using namespace std;

vector<int> nums;
int target_num;
int ans =0;

void dfs(int sum,int cnt){
    
    int cur_num = nums[cnt];
    
    if(cnt >= nums.size()){
        if(sum == target_num){
            ans++;
        }
        return;
    }
    
    dfs(sum + cur_num,cnt+1);
    dfs(sum - cur_num,cnt+1);
    
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    target_num = target;
    
    
    for(int i=0;i<numbers.size();i++){    
        nums.push_back(numbers[i]);
    }
    
    dfs(0,0);
    
    answer = ans;
    
    return answer;
}