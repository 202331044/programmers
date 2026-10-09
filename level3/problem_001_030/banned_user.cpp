#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool compare_id(const string& u_id, const string& b_id)
{
    if(u_id.size() != b_id.size()) 
        return false;
    
    for(int i = 0; i < u_id.size(); ++i)
    {
        if(b_id[i] == '*') continue;
        if(u_id[i] != b_id[i]) return false;
    }
    
    return true;
}

// void dfs(int idx,
//          vector<bool> count,
//          vector<vector<bool>>& answer,
//          vector<string>& banned_id,
//          unordered_map<string, int>& id_to_idx,
//          unordered_map<string, vector<string>>& candidated_id)      
// {

//     if(idx == banned_id.size())
//     {
//         if(answer.size() == 0)
//         {
//             answer.push_back(count);
//             return;
//         }
           
//         for(vector<bool>& ans: answer)
//         {
//             bool isStop = true;
            
//             for(int i = 0; i < count.size(); ++i)
//             {   
//                 if(ans[i] != count[i])
//                 {
//                     isStop = false;
//                     break;
//                 }  
//             }
            
//             if(isStop) return;
//         }
        
//         answer.push_back(count);
//         return;
//     }
    
//     string b_id = banned_id[idx];
    
//     for(const string& u_id: candidated_id[b_id])
//     {
//         int id = id_to_idx[u_id];
        
//         if(count[id] == false)
//         {
//             count[id] = true;
                
//             dfs(idx + 1, count, answer,
//                 banned_id, id_to_idx, candidated_id);

//             count[id] = false;
//         }
//     }
// }

void dfs(int idx, int mask,
        const vector<vector<int>>& candidates,
        unordered_set<int>& answer)
{
    if(idx == candidates.size())
    {
        answer.insert(mask);
        return;
    }
    
    for(int id: candidates[idx])
    {
        if(mask & (1 << id)) continue;

        dfs(idx + 1, (mask | (1 << id)), candidates, answer);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
//     int n = user_id.size();
    
//     unordered_map<string, vector<string>> candidated_id;
//     unordered_map<string, int> id_to_idx;
    
//     for(int idx = 0; idx < n; ++idx)
//     {
//         string id = user_id[idx];
//         id_to_idx[id] = idx;
//     }
        
//     for(string& b_id: banned_id)
//     {
//         if(candidated_id.find(b_id) != candidated_id.end())
//             continue;
        
//         for(string& u_id: user_id)
//         {
//             if(compare_id(u_id, b_id))
//                 candidated_id[b_id].push_back(u_id);
//         }
//     }

//     vector<bool> count(n, false);
//     vector<vector<bool>> answer;
    
//     int idx = 0;
//     dfs(idx, count, answer, banned_id, id_to_idx, candidated_id);
    
//     return answer.size();

    vector<vector<int>> candidates(banned_id.size());
    
    for(int i = 0; i < banned_id.size(); ++i)
    {
        for(int j = 0; j < user_id.size(); ++j)
        {
            if(compare_id(user_id[j], banned_id[i]))
                candidates[i].push_back(j);
        } 
    }
    
    int idx = 0;
    int mask = 0;
    unordered_set<int> answer;
    
    dfs(idx, mask, candidates, answer);
    
    return answer.size();
}
