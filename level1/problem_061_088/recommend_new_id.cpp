#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    string answer;
    
    for(char& ch: new_id)
    {
        if(isalpha(ch)) answer += tolower(ch);
        else if(isdigit(ch) || ch == '_' || ch == '-' || ch == '.')
        {
            if(ch == '.')
            {
                if(!answer.empty() && answer.back() != '.')
                    answer += '.';
            }
            else
                answer += ch;
        }
    }
    
    if(answer.size() >= 16) 
        answer = answer.substr(0, 15);
    
    if(!answer.empty() && answer.back() == '.') 
        answer = answer.substr(0, answer.size() - 1);
    
    if(answer.empty()) 
        answer = "a";
    
    if(answer.size() <= 2) 
        answer.insert(answer.end(), (3 - answer.size()), answer.back());
    
    return answer;
}
