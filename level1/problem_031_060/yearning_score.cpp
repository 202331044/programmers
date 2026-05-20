#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    unordered_map<string, int> m;
    
    for(int i = 0; i < name.size(); ++i)
        m[name[i]] = yearning[i];
    
    vector<int> answer;
    
    for(const auto& names: photo)
    {
        int score = 0;
        for(const string& str: names)
            score += m[str];
        
        answer.push_back(score);
    }
    
    return answer;
}
