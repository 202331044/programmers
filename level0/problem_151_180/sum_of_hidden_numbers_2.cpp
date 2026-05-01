#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string my_string) {
    int sum = 0, num = 0;
    string str;
    
    for(char ch: my_string)
    {
        // if(isdigit(ch)) str += ch;
        // else if(!str.empty())
        // {
        //     sum += stoi(str);
        //     str.clear();
        // }
        
        if(isdigit(ch)) num = num * 10 + ch - '0';
        else
        {
            sum += num;
            num = 0;
        }
    }
    
    sum += num;
    //if(!str.empty()) sum += stoi(str);
    
    return sum;
}
