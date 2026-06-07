#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    bool isFirst = true;
    for(char& ch: s)
    {
        if(ch == ' ') 
            isFirst = true;
        else if(isalpha(ch))
        {
            ch = isFirst == true ? toupper(ch) : tolower(ch);
            isFirst = false;
        }
        else
            isFirst = false;
    }
    
    return s;
}
