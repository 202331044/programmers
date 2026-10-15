#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// int bfs(const vector<vector<int>>& routes, vector<int>& dist)
// {
//     int n =  routes.size();
//     int maxDist = 0;
    
//     queue<int> que;
//     que.push(1);
//     dist[1] = 0;
    
//     while(!que.empty())
//     {
//         int cur = que.front();
//         que.pop();
        
//         for(int next: routes[cur])
//         {
//             if(dist[next] == -1)
//             {
//                 dist[next] = dist[cur] + 1;
                
//                 if(maxDist < dist[next]) 
//                     maxDist = dist[next];
                
//                 que.push(next);
//             }
//         }
//     }
    
//     return maxDist;
// }

void bfs(const vector<vector<int>>& routes, vector<int>& dist)
{
    queue<int> que;
    que.push(1);
    dist[1] = 0;
    
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        
        for(int next: routes[cur])
        {
            if(dist[next] == -1)
            {
                dist[next] = dist[cur] + 1;
                que.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    
    vector<vector<int>> routes(n + 1);
    
    for(const auto& e: edge)
    {
        int u = e[0];
        int v = e[1];
        
        routes[u].push_back(v);
        routes[v].push_back(u);
    }
    
    vector<int> dist(n + 1, -1);
    
//     int maxDist = bfs(routes, dist);
//     int answer = 0;
    
//     for(int i = 2; i <= n; ++i)
//         if(maxDist == dist[i]) 
//             answer++;
    
//     return answer;
    
    bfs(routes, dist);
    
    int maxDist = *max_element(dist.begin(), dist.end());
    
    return count(dist.begin() + 1, dist.end(), maxDist);
}
