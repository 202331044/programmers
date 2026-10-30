#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dijkstra(
    const int s, 
    const vector<vector<pair<int, int>>>& routes, 
    vector<int>& dist)
{
    priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>
    > que;
    
    que.push({0, s});
    dist[s] = 0;
    
    while(!que.empty())
    {
        auto[fare, cur] = que.top();
        que.pop();
        
        if(fare > dist[cur]) continue;
        
        for(auto& [next, nextfare]: routes[cur])
        {
            if(fare + nextfare < dist[next])
            {
                dist[next] = fare + nextfare;
                que.push({fare + nextfare, next});
            }   
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
//     int MAX = 100000 * (n + 1); 
//     vector<vector<int>> costs(n + 1, vector<int>(n + 1, MAX));
    
//     for(const auto& fare: fares)
//     {
//         costs[fare[0]][fare[1]] = fare[2];
//         costs[fare[1]][fare[0]] = fare[2];
//     }
    
//     for(int k = 1; k <= n; ++k)
//         for(int i = 1; i <= n; ++i)
//             for(int j = 1; j <= n; ++j)
//                 if(costs[i][k] + costs[k][j] <= costs[i][j])
//                     costs[i][j] = costs[i][k] + costs[k][j];

//     int answer = costs[s][a] + costs[s][b];
    
//     for(int k = 1; k <= n; ++k)
//     {
//         int u = costs[s][k];
//         int v = costs[k][a];
//         int z = costs[k][b];
        
//         if(s == k) u = 0;
//         if(k == a) v = 0;
//         if(k == b) z = 0;
        
//         answer = min(answer, u + v + z);
//     }

//     return answer;
    
    const int MAX = 100000 * (n + 1);
    vector<vector<pair<int, int>>> routes(n + 1);
    
    for(const auto& fare: fares)
    {
        routes[fare[0]].push_back({fare[1], fare[2]});
        routes[fare[1]].push_back({fare[0], fare[2]});
    }
    
    vector<int> dist1(n + 1, MAX);
    vector<int> dist2(n + 1, MAX);
    vector<int> dist3(n + 1, MAX);
    
    dijkstra(s, routes, dist1);
    dijkstra(a, routes, dist2);
    dijkstra(b, routes, dist3);
    
    int answer = MAX;
    for(int i = 1; i <= n; ++i)
        answer = min(answer, dist1[i] + dist2[i] + dist3[i]);
    
    return answer;

}
