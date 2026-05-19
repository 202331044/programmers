#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto command: commands)
    {
        int i = command[0], j = command[1], k = command[2];
        
        vector<int> tmp(array.begin() + (i - 1), array.begin() + j);
        sort(tmp.begin(), tmp.end());
        
        answer.push_back(tmp[k - 1]);
    }
    
    return answer;
}
