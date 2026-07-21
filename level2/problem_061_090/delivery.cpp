#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
//     vector<vector<int>> routes(N + 1, vector<int>(N + 1, K + 1));
    
//     for(auto& node: road)
//     {
//         int u = node[0], v = node[1], dist = node[2];
        
//         routes[u][v] = min(routes[u][v], dist);
//         routes[v][u] = min(routes[v][u], dist);
//     }
    
//     vector<int> minDist(N + 1, K + 1);
//     minDist[1] = 0;
    
//     queue<int> que;
//     que.push(1);

//     while(!que.empty())
//     {
//         int cur = que.front();
//         que.pop();

//         for(int next = 1; next < N + 1; ++next)
//         {
//             int newDist = minDist[cur] + routes[cur][next];
            
//             if(newDist <= K && newDist < minDist[next])
//             {
//                 minDist[next] = newDist;
//                 que.push(next);
//             }
//         }
//     }
    
//     int answer = 0;
//     for(int i = 0; i < N + 1; ++i)
//         if(minDist[i] <= K) answer++;

//     return answer;
    
    
    vector<vector<pair<int, int>>> routes(N + 1);
    
    for(auto& r: road)
    {
        int u = r[0], v = r[1], dist = r[2];
        routes[u].emplace_back(v, dist);
        routes[v].emplace_back(u, dist);
    }
    
    vector<int> dist(N + 1, K + 1);
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty())
    {
        auto [cost, cur] = pq.top();
        pq.pop();
        
        if(dist[cur] < cost) continue;
        
        for(auto [next, next_cost]: routes[cur])
        {
            if(dist[next] > cost + next_cost)
            {
                dist[next] = cost + next_cost;
                pq.push({dist[next], next});
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= N; ++i)
        if(dist[i] <= K) answer++;
    
    return answer;
}
