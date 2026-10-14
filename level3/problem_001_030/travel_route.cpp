#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

// void dfs(const int n,
//          const string src,
//          vector<string>& answer, 
//          vector<string> tmp,
//          unordered_map<string, 
//          map<string, int>>& um)
// {
//     if(!answer.empty()) return;
    
//     if(tmp.size() == n) 
//     {   
//         answer = tmp;
//         return;
//     }
    
//     for(auto& it: um[src])
//     {
//         if(it.second > 0)
//         {
//             it.second--;
//             string dst = it.first;
//             tmp.push_back(dst);
            
//             dfs(n, dst, answer, tmp, um);

//             it.second++;
//             tmp.pop_back();
//         }
//     }
// }

void dfs(const string& src,
         vector<string>& answer, 
         unordered_map<string, 
                        priority_queue<string, 
                                       vector<string>, 
                                       greater<string>>>& graph)
{
    auto& pq = graph[src];
    
    while(!pq.empty())
    {
        string dst = pq.top();
        pq.pop();
        
        dfs(dst, answer, graph);
    }
    
    answer.push_back(src);
}
vector<string> solution(vector<vector<string>> tickets) {
//     int n = tickets.size() + 1;
    
//     unordered_map<string, map<string, int>> um;
//     for(const auto& ticket: tickets)
//     {
//         string src = ticket[0];
//         string dst = ticket[1];
//         um[src][dst]++;
//     }
    
//     vector<string> answer;
//     vector<string> tmp = {"ICN"};
    
//     dfs(n, "ICN", answer, tmp, um);
    
//     return answer;
    
    unordered_map<string, 
                  priority_queue<string, vector<string>, greater<string>>> graph;
    
    for(auto& ticket: tickets)
       graph[ticket[0]].push(ticket[1]); 
    
    vector<string> answer;
    dfs("ICN", answer, graph);
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
