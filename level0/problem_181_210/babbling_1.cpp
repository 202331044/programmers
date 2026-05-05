#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> can = { "aya", "ye", "woo", "ma"};
    for(string& str: babbling)
    {
        int size = str.size();
        
        for(string& s: can)
            if(str.find(s) != string::npos) size -= s.size();
        
        if(size == 0) answer++;
    }
    
    return answer;
}
