#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    int n = s.size();
    
    for(int i = 0; i < n; ++i)
    {
        stack<char> stk;
        
        for(int j = i; j < i + n; ++j)
        {

            if(!stk.empty() &&
               ((stk.top() == '[' && s[j % n] == ']') ||
               (stk.top() == '{' && s[j % n] == '}') ||
               (stk.top() == '(' && s[j % n] == ')')))
            {
                stk.pop();
            }
            else
                stk.push(s[j % n]);
        }

        if(stk.size() == 0)
            answer++;
    }
    
    return answer;
}
