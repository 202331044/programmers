#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// void dfs(int k, int& answer, const int type,
//         vector<bool> infections, 
//         const vector<vector<int>>& edges,
//         const vector<vector<vector<int>>>& routes)
// {
//     queue<int> que;
    
//     for(int i = 1; i < infections.size(); ++i)
//         if(infections[i]) que.push(i);
    
//     while(!que.empty())
//     {
//         int cur = que.front();
//         que.pop();

//         for(int next: routes[cur][type])
//         {
//             if(infections[next] == false)
//             {
//                 que.push(next);
//                 infections[next] = true;
//             }
//         }
//     }
    
//     k--;
    
//     if(k == 0)
//     {
//         int cnt = 0;
        
//         for(int i = 1; i < infections.size(); ++i)
//             if(infections[i]) cnt++;

//         answer = max(answer, cnt);
//         return;
//     }
    
//     for(int nextType = 1; nextType <= 3; ++nextType)
//     {
//         if(type == nextType) continue;
//         dfs(k, answer, nextType, infections, edges, routes);
//     }
// }

void spread(const int type,
            vector<bool>& infected,
            const vector<vector<vector<int>>>& routes)
{
    queue<int> que;
    
    for(int i = 1; i < infected.size(); ++i)
        if(infected[i]) que.push(i);
    
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();

        for(int next: routes[cur][type])
        {
            if(infected[next] == false)
            {
                que.push(next);
                infected[next] = true;
            }
        }
    }
}

void dfs2(int remainder, int& answer, const int type, 
          vector<bool> infected,
          const vector<vector<vector<int>>>& routes)
{
    spread(type, infected, routes);
    remainder--;

    if(remainder == 0)
    {
        int cnt = 0;
        
        for(int i = 1; i < infected.size(); ++i)
            if(infected[i]) cnt++;

        answer = max(answer, cnt);
        return;
    }
    
    for(int nextType = 1; nextType <= 3; ++nextType)
    {
        if(type == nextType) continue;
        dfs2(remainder, answer, nextType, infected, routes);
    }      
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
//     vector<vector<vector<int>>> routes(n+1, vector<vector<int>>(4));
    
//     for(auto& edge: edges)
//     {
//         int x = edge[0];
//         int y = edge[1];
//         int t = edge[2];
//         routes[x][t].push_back(y);
//         routes[y][t].push_back(x);
//     }
    
//     vector<bool> infections(n + 1, false);
//     infections[infection] = true;
    
//     int answer = 1;
//     for(int type = 1; type <= 3; ++type)
//         dfs(k, answer, type, infections, edges, routes);
    
//     return answer;
    vector<bool> infected(n + 1, false);
    infected[infection] = true;
    vector<vector<vector<int>>> routes(n+1, vector<vector<int>>(4));
    
    for(auto& edge: edges)
    {
        int x = edge[0];
        int y = edge[1];
        int t = edge[2];
        routes[x][t].push_back(y);
        routes[y][t].push_back(x);
    } 
    
    int answer = 0;
    for(int type = 1; type <= 3; ++ type)
        dfs2(k, answer, type, infected, routes);
    
    return answer;
}
