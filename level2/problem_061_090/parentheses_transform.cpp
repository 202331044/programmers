#include <string>
#include <vector>

using namespace std;

string func(string& str)
{
    if(str.empty()) return "";
    
    bool isRight = true;
    int balance = 0;
    string u, v;
    
    for(int i = 0; i < str.size(); ++i)
    {
        u.push_back(str[i]);
        
        if(u.back() == '(') balance++;
        else balance--;
        
        if(balance < 0) isRight = false;
        
        if(balance == 0)
        {
            v = str.substr(i + 1);
            break;
        }
    }
    

    if(isRight) 
        return u + func(v);
    else 
    {
        string new_str = "(";
        new_str += func(v);
        new_str += ')';
        
        for(int i = 1; i < u.size() - 1; ++i)
        {
            if(u[i] == '(') new_str += ')';
            else new_str += '(';
        }
        
        return new_str;
    }
}

string solution(string p) {

    string answer = func(p);
    return answer;
}
