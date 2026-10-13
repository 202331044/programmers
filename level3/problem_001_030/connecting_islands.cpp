#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> costs) {

    vector<vector<pair<int, int>>> routes(n);
    
    for(int i = 0; i < costs.size(); ++i)
    {
        int u = costs[i][0];
        int v = costs[i][1];
        int cost = costs[i][2];
        
        routes[u].push_back({v, cost});
        routes[v].push_back({u, cost});
    }

    priority_queue<pair<int, pair<int, int>>, 
               vector<pair<int, pair<int, int>>>,
               greater<pair<int, pair<int, int>>>> pq;
    
    for(auto&[v, cost]: routes[0])
        pq.push({cost, {0, v}});

    vector<bool> visited(n, false);
    visited[0] = true;
    
    int answer = 0;
    
    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        
        int cost = cur.first;
        int u = cur.second.first;
        int v = cur.second.second;
        
        if(visited[v]) continue;
        
        answer += cost;
        visited[v] = true;
        
        for(auto& [next, nextCost]: routes[v])
        {
            if(visited[next] == true) continue;
            pq.push({nextCost, {v, next}});
        }
    }
    
    return answer;
}
