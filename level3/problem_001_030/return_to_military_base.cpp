#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(int destination, vector<int>& dist, vector<vector<int>>& routes)
{
    queue<int> que;
    que.push(destination);
    dist[destination] = 0;
    
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        
        for(int next: routes[cur])
        {
            if(dist[next] != -1) continue;
            
            dist[next] = dist[cur] + 1;
            que.push(next);
        }
    }
}


vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    
    vector<vector<int>> routes(n + 1);
    
    for(const auto& road: roads)
    {
        int u = road[0];
        int v = road[1];
        
        routes[u].push_back(v);
        routes[v].push_back(u);
    }
    
    vector<int> dist(n + 1, -1);
    bfs(destination, dist, routes);
    
    vector<int> answer;
    for(int src: sources)
        answer.push_back(dist[src]);
    
    return answer;
}
