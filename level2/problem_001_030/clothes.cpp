#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> type;
    
    for(auto& vec: clothes)
        type[vec[1]]++;
    
    int answer = 1;
    
    for(auto& it: type)
        answer *= (it.second + 1);
    
    return answer - 1;
}
