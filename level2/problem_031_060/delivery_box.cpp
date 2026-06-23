#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
//     vector<pair<int, int>> vec;
//     for(int i = 0; i < order.size(); ++i)
//         vec.emplace_back(order[i], i + 1);

//     sort(vec.begin(), vec.end());
    
//     int cnt = 1;
//     stack<int> stk;
//     for(int j = 0; j < order.size(); ++j)
//     {
//         while(!stk.empty() && stk.top() == cnt)
//         {
//             stk.pop();
//             cnt++;
//         }

//         if(vec[j].second == cnt)
//             cnt++;
//         else
//             stk.push(vec[j].second);
//     }
    
//     while(!stk.empty())
//     {
//         if(stk.top() == cnt)
//         {
//             stk.pop();
//             cnt++;
//         }
//         else
//             break;
//     }
    
//     return cnt - 1;
    
    stack<int> pos;
    int idx = 0;
    
    for(int i = 1; i <= order.size(); ++i)
    {
        pos.push(i);
        
        while(!pos.empty() && pos.top() == order[idx])
        {
            pos.pop();
            idx++;
        }
    }
    
    return idx;
}
