#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string ret;
    int mode = 0;
    
    for(int i = 0; i < code.size(); ++i)
    {
        // if(mode == 0)
        // {
        //     if(code[i] != '1' && i % 2 == 0) ret.push_back(code[i]);
        //     else if(code[i] == '1') mode = 1;
        // }
        // else
        // {
        //     if(code[i] != '1' && i % 2 != 0) ret.push_back(code[i]);
        //     else if(code[i] == '1') mode = 0;
        // }
        
        if(code[i] == '1') mode = 1 - mode;
        else if(mode == i % 2) ret.push_back(code[i]);
    }
    
    if(ret.empty()) return "EMPTY";
    return ret;
}
