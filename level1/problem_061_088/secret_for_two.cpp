#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string s, string skip, int index) {
    string answer;
    vector<bool> skiped(26, 0);
    
    for(char c: skip)
        skiped[c - 'a'] = true;
    
    for(char ch: s)
    {
        int cnt = 0;
        char newch;
        
        for(int i = 1; ; ++i)
        {
            newch = (ch - 'a' + i) % 26;
            
            if(skiped[newch] == 0) cnt++;
            if(cnt == index) break;
        }
        
        answer += newch + 'a';
    }

    return answer;
}
