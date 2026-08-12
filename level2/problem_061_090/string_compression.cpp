#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    for(int len = 1; len <= s.size() / 2; ++len)
    {
        string pre = s.substr(0, len);
        int cnt = 1;
        int length = 0;
        
        for(int idx = len; idx < s.size(); idx += len)
        {
            string cur = s.substr(idx, len);
            if(pre == cur) cnt++;
            else
            {
                if(cnt > 1)
                    length += to_string(cnt).size() + pre.size();
                else
                    length += pre.size();
                
                pre = cur;
                cnt = 1;
            }
        }
        
        length += pre.size();
        if(cnt > 1) length += to_string(cnt).size();

        answer = answer < length ? answer : length;
    }
    
    return answer;
}
