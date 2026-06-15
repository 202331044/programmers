#include <string>
#include <vector>

using namespace std;

void dfs(const vector<int>& numbers, int pos, int sum, int target, int& answer)
{
    if(pos == numbers.size())
    {
        if(sum == target)
            answer++;
        return;
    }
    
    dfs(numbers, pos + 1, sum + numbers[pos], target, answer);
    dfs(numbers, pos + 1, sum - numbers[pos], target, answer);
}

int solution(vector<int> numbers, int target) {
    //int answer = 0;
    
    vector<int> dp(2001, 0);
    int offset = 1000;
    dp[offset] = 1;
    
    for(int num: numbers)
    {
        vector<int> next(2001, 0);
        
        for(int i = 0; i < 2001; ++i)
        {
            if(dp[i] == 0) continue;
            
            next[i + num] += dp[i];
            next[i - num] += dp[i];
        }
        
        dp = next;
    }
    
    return dp[offset + target];
    
    // dfs(numbers, 0, 0, target, answer);
    
    //return answer;
}
