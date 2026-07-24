#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;

void broute_force(int idx, string str, const string& order, 
                  vector<map<string, int>>& vec)
{
    if(str.size() == order.size()) return;
    
    for(int i = idx; i < order.size(); ++i)
    {
        vec[str.size() + 1][str + order[i]]++;
        broute_force(i + 1, str + order[i], order, vec);
    }
}

void dfs(const int target_size, int idx, string& cur, const string& order, 
                  vector<unordered_map<string, int>>& vec)
{
    if(target_size - cur.size() > order.size() - idx) 
        return;
    
    if(cur.size() == target_size)
    {
        vec[target_size][cur]++;
        return;
    }
        
    for(int i = idx; i < order.size(); ++i)
    {
        cur.push_back(order[i]);
        dfs(target_size, i + 1, cur, order, vec);
        cur.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
//     vector<map<string, int>> vec(11);
    
//     for(string& order: orders)
//     {
//         sort(order.begin(), order.end());
//         string str;
//         broute_force(0, str,  order, vec);

//     }
    
//     vector<int> len(11, 2);
//     for(int size: course)
//     {
//         for(auto& [key, value]: vec[size])
//         {
//             if(len[key.size()] < value)
//                 len[key.size()] = value;
//         }
//     }
    
//     vector<string> answer;
//     for(int size: course)
//     {
//         for(auto& [key, value]: vec[size])
//         {
//             if(len[key.size()] == value)
//                 answer.push_back(key);
//         }
//     }
    
//     sort(answer.begin(), answer.end());
    
//     return answer;
    
    vector<unordered_map<string, int>> vec(11);
    for(string& order: orders)
    {
        sort(order.begin(), order.end());
        string str;
        
        for(int target: course)
        {
            if(order.size() >= target) 
                dfs(target, 0, str,  order, vec);
        }
            
    }
    
    vector<int> len(11, 2);
    for(int size: course)
    {
        for(auto& [key, value]: vec[size])
        {
            if(len[size] < value)
                len[size] = value;
        }
    }
    
    vector<string> answer;
    for(int size: course)
    {
        for(auto& [key, value]: vec[size])
        {
            if(len[size] == value)
                answer.push_back(key);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
    
}
