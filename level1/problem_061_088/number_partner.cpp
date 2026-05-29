#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> cntX(10, 0), cntY(10, 0);
    
    for(const char& ch: X)
        cntX[ch - '0']++;
    
    for(const char& ch: Y)
        cntY[ch - '0']++;
    
    for(int i = 9; i >= 0; --i)
    {
        int cnt = min(cntX[i], cntY[i]);
        if(cnt != 0) 
            answer.insert(answer.end(), cnt, i + '0');
    }
        
    if(answer.empty()) return "-1";
    if(answer[0] == '0') return "0";
    
    return answer;
}
