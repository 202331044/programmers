#include <queue>
#include <vector>

using namespace std;

int bfs(int x, int y, int n)
{
    vector<int> dist(y + 1, -1);
    queue<int> que;
    que.push(x);
    dist[x] = 0;
    
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        
        if(cur == y) 
            return dist[cur];  
       
        vector<int> nodes = {cur * 3, cur * 2, cur + n};
        for(int next: nodes)
        {
            if(next <= y && dist[next] == -1)
            {
                que.push(next);
                dist[next] = dist[cur] + 1;
            }
        }
    }
    
    return -1;
}

int solution(int x, int y, int n) {
    //return bfs(x, y, n);
    
    const int INF = y + 1;
    vector<int> dp(y + 1, INF);
    dp[x] = 0;
    
    for(int cur = x; cur <= y; ++cur)
    {
        if(dp[cur] == INF) continue;
        int nodes[3] = {cur * 3, cur * 2, cur + n};
        
        for(int next: nodes)
        {
            if(next <= y)
                dp[next] = min(dp[next], dp[cur] + 1);
        }
    }
    
    if(dp[y] == INF) return -1;
    return dp[y];
}
