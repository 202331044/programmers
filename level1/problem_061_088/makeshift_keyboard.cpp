#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int> pos(26, -1);
    
    for(const string& key: keymap)
    {
        for(int i = 0; i < key.size(); ++i)
        {
            int idx = key[i] - 'A';
            if(pos[idx] == -1) pos[idx] = i + 1;
            else pos[idx] = min(pos[idx], i + 1);
        }
    }
    
    for(const string& target: targets)
    {
        int cnt = 0;
        bool can = true;
        
        for(const char& ch: target)
        {
            if(pos[ch - 'A'] == -1) 
            {
                answer.push_back(-1);
                can = false;
                break;
            }
            
            cnt += pos[ch - 'A'];
        }
        
        if(can) answer.push_back(cnt); 
    }
    
    return answer;
}
