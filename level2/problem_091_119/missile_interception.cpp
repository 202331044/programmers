#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {

//     sort(targets.begin(), targets.end(), [](const auto& a, const auto& b)
//          {
//              if(a[0] != b[0]) return a[0] < b[0];
//              else return a[1] <= b[1];
//          });
    
//     vector<pair<int, int>> arr;
//     for(int i = 0; i < targets.size(); ++i)
//     {
//         arr.push_back({targets[i][0], i});
//         arr.push_back({targets[i][1], i});
//     }
    
//     sort(arr.begin(), arr.end(), [](const auto& a, const auto& b)
//      {
//          if(a.first != b.first) return a.first < b.first;
//          else return a.second < b.second;
//      });
    
//     int answer = 0;
//     int idx = -1;
//     stack<pair<int, int>> stk;
    
//     for(const auto& [x, num]: arr)
//     {
//         if(num <= idx) continue;
        
//         if(stk.empty()) stk.push({x, num});
//         else if(stk.top().second >= num)
//         {
//             while(!stk.empty())
//                 {
//                     idx = max(idx, stk.top().second);
//                     stk.pop();
//                 }
                
//                 answer++;
//         }
//         else
//             stk.push({x, num});
//     }
    
//     if(!stk.empty()) answer++;
    
//     return answer;
    
    sort(targets.begin(), targets.end(), [](const auto& a, const auto& b)
         {
             return a[1] < b[1];
         });
    
    int answer = 0;
    int pos = 0;
    for(const auto& target: targets)
    {
        int s = target[0];
        int e = target[1];
        
        if(pos <= s)
        {
            pos = e;
            answer++;
        }
    }
    
    return answer;
}
