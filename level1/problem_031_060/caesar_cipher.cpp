#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
//     int z = 'z';

//     for(char& ch: s)
//     {
//         int tmp = ch + n;
        
//         if(ch >= 'a' && ch <= 'z') 
//             ch = tmp > 'z' ?  tmp - 'z' - 1 + 'a' : tmp;
        
//         if(ch >= 'A' && ch <= 'Z') 
//             ch = tmp > 'Z' ?  tmp - 'Z' - 1 + 'A' : tmp;
//     }
    
//     return s;

    for(char& ch: s)
    {
        if(ch >= 'a' && ch <= 'z') ch = (ch - 'a' + n) % 26 + 'a';
        else if(ch >= 'A' && ch <= 'Z') ch = (ch - 'A' + n) % 26 + 'A';
    }
    
    return s;
}
