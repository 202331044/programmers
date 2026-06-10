#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

bool isValid(unordered_map<string, int>& target, 
             unordered_map<string, int>& window)
{
    for(auto& p: target)
    {
        if(window[p.first] != p.second)
            return false;
    }
    
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
//     unordered_map<string, int> m;
    
//     for(int i = 0; i < want.size(); ++i)
//         m[want[i]] = number[i];
    
//     unordered_map<string, int> count = m;
//     queue<string> que;
//     int answer = 0;
    
//     for(int j = 0; j < discount.size(); ++j)
//     {
//         string product = discount[j];
        
//         if(m.count(product) == 0)
//         {
//             que = queue<string>();
//             count = m;
//         }
//         else
//         {
//             while(!que.empty() && count[product] <= 0)
//             {
//                 count[que.front()]++;
//                 que.pop();
//             }

//             que.push(product);
//             count[product]--;
            
//             if(que.size() == 10)
//             {
//                 answer++;
//                 count[que.front()]++;
//                 que.pop();
//             }
//         }
//     }
    
//     return answer;
    
    int answer = 0;
    
    unordered_map<string, int> target;
    for(int i = 0; i < want.size(); ++i)
        target[want[i]] = number[i];
    
    unordered_map<string, int> window;
    for(int j = 0; j < 10; ++j)
        window[discount[j]]++;
    
    if(isValid(target, window))
        answer++;
    
    for(int k = 10; k < discount.size(); ++k)
    {
        window[discount[k - 10]]--;
        window[discount[k]]++;
        
        if(isValid(target, window))
            answer++;
    }
    
    return answer;
}
