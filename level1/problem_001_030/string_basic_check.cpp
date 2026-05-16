#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.size() != 4 && s.size() != 6) return false;
    
    for(char ch: s)
        if(isdigit(ch) == false) return false;
    
    return true;
}
