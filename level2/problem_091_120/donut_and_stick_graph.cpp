#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

pair<int, int> bfs(const int start, const vector<vector<int>>& out, 
                  vector<bool>& visited)
{
    queue<int> que;
    
    que.push(start);
    visited[start] = true;
    
    int edge = 0;
    int node = 0;
    
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        node++;
        
        for(int next: out[cur])
        {
            edge++;
            if(visited[next] == false)
            {
                que.push(next);
                visited[next] = true;
            }
        }
    }
    
    return {node, edge};
}

vector<int> solution(vector<vector<int>> edges) {
//     vector<int> answer(4, 0);
    
//     vector<vector<int>> out(1000001);
//     vector<vector<int>> in(1000001);
    
//     for(auto& edge: edges)
//     {
//         int s = edge[0];
//         int e = edge[1];
        
//         out[s].push_back(e);
//         in[e].push_back(s);
//     }
    
    
//     int route = 0;
//     for(int i = 1; i < out.size(); ++i)
//     {
//         if(out[i].size() >= 2 && in[i].size() == 0)
//         {
//             route = i;
//             break;
//         }
//     }
    
//     answer[0] = route;
//     vector<bool> visited(1000001, false);
    
//     for(int start: out[route])
//     {
//         auto [node, edge] = bfs(start, out, visited);
//         if(node == edge)
//             answer[1]++;
//         else if(node - 1 == edge)
//             answer[2]++;
//         else
//             answer[3]++;
//     }
    
//     return answer;
    
    vector<int> answer(4, 0);
    
    vector<int> out(1000001, 0), in(1000001, 0);
    
    for(auto& edge: edges)
    {
        int s = edge[0];
        int e = edge[1];
        
        out[s]++;
        in[e]++;
    }
    
    int route = 0;
    for(int i = 1; i < out.size(); ++i)
    {
        if(out[i] >= 2 && in[i] == 0)
        {
            route = i;
            break;
        }
    }
    
    for(int i = 1; i < out.size(); ++i)
    {
        if(i == route) continue;
        
        if(out[i] == 0 && in[i] >= 1) answer[2]++;
        else if(out[i] == 2) answer[3]++;
    }
    
    answer[0] = route;
    answer[1] = out[route] - (answer[2] + answer[3]);
    
    return answer;
}
