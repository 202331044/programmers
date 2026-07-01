#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
//     int answer = 0;
    
//     for(string& tree: skill_trees)
//     {
//         bool isValid = true;
//         bool isStop = false;
//         int pre = -1;
        
//         for(char ch: skill)
//         {
//             int idx = tree.find(ch);
            
//             if(idx == string::npos)
//                 isStop = true;
//             else if(isStop || pre > idx)
//             {
//                 isValid = false;
//                 break;
//             }
//             else
//                 pre = idx;
//         }
        
//         if(isValid) answer++;
//     }
    
//     return answer;
    
    int answer = 0;
    
    for(string& tree: skill_trees)
    {
        bool isValid = true;
        int cnt = 0;
        
        for(char ch: tree)
        {
            auto idx = skill.find(ch);
            if(idx == string::npos) continue;
            
            if(idx == cnt)
                cnt++;
            else
            {
                isValid = false;
                break;
            }
        }
        
        if(isValid) answer++;
    }
    
    return answer;
}
