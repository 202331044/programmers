#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
//     stack<char> stk;
    
//     for(char& ch: s)
//     {
//         if(!stk.empty() && stk.top() == ch)
//             stk.pop();
//         else
//             stk.push(ch);
//     }
    
//     return stk.empty() == true;
    
    string str;
    
    for(char ch: s)
    {
        if(!str.empty() && str.back() == ch)
            str.pop_back();
        else
            str.push_back(ch);
    }
    
    return str.empty();
}
