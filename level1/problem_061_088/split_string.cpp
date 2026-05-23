#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int start = 0;
    int cnt1 = 1, cnt2 = 0;
    
    for(int i = start + 1; i < s.size(); ++i)
    {
        if(s[start] == s[i]) cnt1++;
        else cnt2++;
        
        if(cnt1 == cnt2)
        {
            answer++;
            start = i + 1;
            
            if(start == s.size()) return answer;
            
            i = start;
            cnt1 = 1;
            cnt2 = 0;
        }
    }

    return answer + 1;
}
