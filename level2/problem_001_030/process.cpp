#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> que;
    priority_queue<int> pq;
    
    for(int i = 0; i < priorities.size(); ++i)
    {
        que.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    int cnt = 0;
    while(!que.empty())
    {
        while(que.front().second != pq.top())
        {
            auto cur = que.front();
            que.pop();
            que.push(cur);
        }
        
        cnt++;
        
        if(que.front().first == location)
            return cnt;
            
        que.pop();
        pq.pop();
    }
}
