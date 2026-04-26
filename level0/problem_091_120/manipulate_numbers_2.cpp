#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    int size = numLog.size();
    
    for(int i = 1; i < size; ++i)
    {
        int diff = numLog[i] - numLog[i - 1];
        
        if(diff == 1) answer += 'w';
        else if(diff == -1) answer += 's';
        else if(diff == 10) answer += 'd';
        else answer += 'a';
    }
    
    return answer;
}
