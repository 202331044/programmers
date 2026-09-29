#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <set>
#include <iterator>

using namespace std;

vector<int> solution(vector<string> operations) {
//     priority_queue<int> maxPq, delMaxPq;
//     priority_queue<int, vector<int>, greater<int>> minPq, delMinPq;
    
//     for(auto& op: operations)
//     {
//         istringstream iss(op);
//         char ch;
//         int num;
        
//         iss >> ch >> num;
        
//         if(ch == 'I')
//         {
//             minPq.push(num);
//             maxPq.push(num);
//         }
//         else
//         {
//             if(num < 0 && !minPq.empty())
//             {
//                 delMaxPq.push(minPq.top());
//                 minPq.pop();
//             }
//             else if(num > 0 && !maxPq.empty())
//             {
//                 delMinPq.push(maxPq.top());
//                 maxPq.pop();
//             }
            
//             while(!delMinPq.empty() && !minPq.empty() &&
//                   delMinPq.top() == minPq.top())
//             {
//                 delMinPq.pop();
//                 minPq.pop();
//             }

//              while(!delMaxPq.empty() && !maxPq.empty() &&
//                    delMaxPq.top() == maxPq.top())
//              {
//                 delMaxPq.pop();
//                 maxPq.pop();
//              }
//         }
//     }
    
    
//     if(minPq.empty() || maxPq.empty()) return {0, 0};
    
//     return {maxPq.top(), minPq.top()};
    
    multiset<int> s;
    
    for(auto& op: operations)
    {
        istringstream iss(op);
        char ch;
        int num;
        
        iss >> ch >> num;
        
        if(ch == 'I') s.insert(num);
        else if(!s.empty())
        {
            if(num < 0) s.erase(s.begin());
            else s.erase(prev(s.end()));
        }
    }
    
    if(s.empty()) return {0, 0};
    return {*s.rbegin(), *s.begin()};
}
