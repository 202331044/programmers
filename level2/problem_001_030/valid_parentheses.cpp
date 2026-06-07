#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
//     stack<char> stk;
    
//     for(char& ch: s)
//     {
//         if(!stk.empty() && stk.top() == '(' && ch == ')') 
//             stk.pop();
//         else
//             stk.push(ch);
//     }
 
//     return stk.empty() == true;
    
    int cnt = 0;
    
    for(char& ch: s)
    {
        if(ch == '(') cnt++;
        else cnt--;
        
        if(cnt < 0) return false;
    }
    
    return cnt == 0;
}
