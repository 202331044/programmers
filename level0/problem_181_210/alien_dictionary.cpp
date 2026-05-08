#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {

//     for(string& str: dic)
//     {
//         if(str.size() < spell.size()) continue;
        
//         bool check = true;
//         unordered_map<char, int> m;
        
//         for(char ch: str) m[ch]++;

//         for(string& s: spell)
//         {
//             if(m[s[0]] != 1)
//             {
//                 check = false;
//                 break;
//             }
//         }

//         if(check) return 1;
//     }
    
//     return 2;
    
    string target;
    for(string& tmp: spell) target += tmp;
    
    sort(target.begin(), target.end());
    
    for(string& str: dic)
    {
        sort(str.begin(), str.end());
        
        if(target == str) return 1;
    }
    
    return 2;
}
