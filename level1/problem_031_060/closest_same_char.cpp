#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {

    vector<int> count(26, -1);
    vector<int> answer(s.size(), -1);

    for(int i = 0; i < s.size(); ++i)
    {
        int ch = s[i] - 'a';
        
        if(count[ch] != -1) 
            answer[i] = (i - count[ch]);

        count[ch] = i;
    }
    
    return answer;
}
