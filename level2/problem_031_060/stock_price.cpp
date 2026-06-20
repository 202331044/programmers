#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> stk;
    
    for(int i = 0; i < prices.size(); ++i)
    {
        while(!stk.empty() && prices[stk.top()] > prices[i])
        {
            int idx = stk.top();
            answer[idx] = i - idx;
            stk.pop();
        }
        
        stk.push(i);
    }
    
    while(!stk.empty())
    {
        int idx = stk.top();
        answer[idx] = prices.size() - 1 - idx;
        stk.pop();
    }
    
    return answer;
}
