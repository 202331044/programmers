#include <string>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<tuple<string, int, int>> order_plans;
    
    for(auto& plan: plans)
    {
        string name = plan[0];
        int start = stoi(plan[1].substr(0, 2)) * 60 + stoi(plan[1].substr(3, 2));
        int playTime = stoi(plan[2]);
        order_plans.push_back({name, start, playTime});
    }
    
    sort(order_plans.begin(), order_plans.end(), 
         [](const tuple<string, int, int>& a, const tuple<string, int, int>& b)
         {
             return get<1>(a) < get<1>(b); 
         });
    
    vector<string> answer;
    stack<pair<string, int>> stk;
    int curTime = 0;
    
    for(auto& plan: order_plans)
    {
        string name = get<0>(plan);
        int start = get<1>(plan);
        int playTime = get<2>(plan);
        
        if(stk.empty())
        {
            stk.push({name, playTime});
            curTime = start;
            continue;
        }  
        
        while(!stk.empty())
        {
            auto [n, p] = stk.top();
            stk.pop();

            if(curTime + p <= start)
            {
                curTime += p;
                answer.push_back(n);
            }
            else
            {
                p -= (start - curTime);
                stk.push({n, p});
                break;
            }
        }
        
        curTime = start;
        stk.push({name, playTime});
    }
    
    while(!stk.empty())
    {
        answer.push_back(stk.top().first);
        stk.pop();
    }
       
    return answer;
}
