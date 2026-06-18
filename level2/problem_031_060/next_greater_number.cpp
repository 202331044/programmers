#include <string>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> stk;
    //stack<pair<int, int>> stk;
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        int number = numbers[i];
        
        if(stk.empty())
        {
            //stk.push({number, i});
            stk.push(i);
            continue;
        }
              
        //while(!stk.empty() && stk.top().first < number)
        while(!stk.empty() && numbers[stk.top()] < number)
        {
            //auto [tmp, idx] = stk.top();
            int idx = stk.top();
            stk.pop();
            answer[idx] = numbers[i];
        }
        
        //stk.push({number, i});
        stk.push(i);
    }
    
    return answer;
}
