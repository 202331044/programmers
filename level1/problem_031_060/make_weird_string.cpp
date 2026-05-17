#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string str;
    int cnt = 0;
    
    for(char& ch: s)
    {
        if(ch == ' ')
        {
            str += ' ';
            cnt = 0;
        }
        else
        {
            if(cnt % 2 == 0) str += toupper(ch);
            else str += tolower(ch);
            cnt++;
        }
    }
    
    return str;
}
