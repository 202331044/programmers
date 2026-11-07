#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// void dfs(
//     int& answer, 
//     int sheep, 
//     int wolf, 
//     vector<int> available,
//     const vector<int>& info,
//     const vector<vector<int>>& routes)
// {
//     answer = max(answer, sheep);
    
//     for(int i = 0; i < available.size(); ++i)
//     {
//         int next = available[i];
//         if(info[next] == 1 && wolf + 1 >= sheep) continue;
        
//         vector<int> new_available = available;
//         new_available.erase(new_available.begin() + i);
        
//         for(int node: routes[next])
//             new_available.push_back(node);
        
//         if(info[next] == 0) 
//             dfs(answer, sheep + 1, wolf, new_available, info, routes);
//         else
//             dfs(answer, sheep, wolf + 1, new_available, info, routes);    
//     }
// }

void dfs(
    int& answer,
    int visited_mask,
    int sheep, 
    int wolf,
    const int n,
    vector<bool>& visited_state,
    const vector<int>& info,
    const vector<int>& parent
)
{
    answer = max(answer, sheep);
    
    for(int i = 1; i < n; ++i)
    {
        if((visited_mask & (1 << i)) != 0) continue;
        if((visited_mask & (1 << parent[i])) == 0) continue;
        if(visited_state[visited_mask | (1 << i)]) continue;
     
        visited_state[visited_mask | (1 << i)] = true;
        
        int newsheep = sheep;
        int newwolf = wolf;
        
        if(info[i] == 0) newsheep++;
        else newwolf++;
        
        if(newsheep > newwolf)
            dfs(
                answer, 
                visited_mask | (1 << i), 
                newsheep, 
                newwolf, 
                n, 
                visited_state,
                info, 
                parent
            );
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
//     vector<vector<int>> routes(n);
    
//     for(const auto& edge: edges)
//         routes[edge[0]].push_back(edge[1]);
    
//     vector<int> available = {0};
//     int answer = 0;
//     int sheep = 0, wolf = 0;

//     dfs(answer, sheep, wolf, available, info, routes);
    
//     return answer;
    
    vector<int> parent(n, 0);
    
    for(const auto& edge: edges)
        parent[edge[1]] = edge[0];
    
    int answer = 0;
    int visited_mask = 1;
    int sheep = 1, wolf = 0;
    vector<bool> visited_state((1 << n), false);
    
    dfs(answer, visited_mask, sheep, wolf, n, visited_state, info, parent);
    
    return answer;
}
