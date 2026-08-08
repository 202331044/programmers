#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    queue <int> orders;
    
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < picks[i]; ++j)
            orders.push(i);
    
    int cnt = 0;
    int sum = 0;
    int size = min(minerals.size(), orders.size() * 5);
    priority_queue<pair<int, int>> pq;
    
    for(int i = 0; i < size; ++i)
    {
        if(i % 5 == 0)
        {
            pq.push({sum, cnt++});
            sum = 0;
        }
        
        if(minerals[i] == "diamond") sum += 100;
        else if(minerals[i] == "iron") sum += 10;
        else sum += 1;
    }
    
    if(sum != 0) pq.push({sum, cnt++});
    
    vector<int> ans(cnt);
    
    while(!pq.empty())
    {
        auto [fatigue, idx] = pq.top();
        pq.pop();
        
        int pick = orders.front();
        orders.pop();
        
        ans[idx] = pick;
    }

    int answer = 0;
    int count = 0;
    
    for(int i = 0; i < size; ++i)
    {
        if(i % 5 == 0)
            count++;
        
        if(ans[count] == 0) answer++;
        else if(ans[count] == 1)
        {
            if(minerals[i] == "diamond") answer += 5;
            else answer++;
        }
        else
        {
            if(minerals[i] == "diamond") answer += 25;
            else if(minerals[i] == "iron") answer += 5;
            else answer++;
        }
    }

    return answer;
}
