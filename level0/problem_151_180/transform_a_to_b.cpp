#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string before, string after) {
//     map<char, int> dict1, dict2;
    
//     for(int i = 0; i < before.size(); ++i)
//     {
//         dict1[before[i]]++;
//         dict2[after[i]]++;
//     }
    
//     for(auto it: dict1)
//     {
//         char ch = it.first;
//         int cnt = it.second;
        
//         if(dict2[ch] != cnt) return 0;
//     }
    
//     return 1;
    
    vector<int> dict(26, 0);
    
    for(char ch: before) dict[ch - 'a']++;
    
    for(char ch: after) dict[ch - 'a']--;
    
    for(int i = 0; i < 26; ++i)
        if(dict[i] != 0) return 0;
    
    return 1;
}
