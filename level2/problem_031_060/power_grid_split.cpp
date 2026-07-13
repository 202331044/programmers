#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int countNode(int u, int v, vector<vector<int>>& trees)
{
    int cnt = 0;
    
    vector<bool> visited(trees.size(), false);
    queue<int> que;
    que.push(u);
    
    visited[u] = true;
    
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        cnt++;
        
        for(auto& next: trees[cur])
        {
            if(visited[next] || (u == next && v == cur) || 
               (u == cur && v == next))
                continue;
            
            que.push(next);
            visited[next] = true;
        }
    }
    
    return cnt;
}

void dfs(int cur, int par, vector<vector<int>>& tree,
         vector<int>& parent, vector<int>& subtree)
{
    parent[cur] = par;
    subtree[cur] = 1;
    
    for(auto next: tree[cur])
    {
        if(next == par) continue;
        dfs(next, cur, tree, parent, subtree);
        subtree[cur] += subtree[next];
    }
}

int solution(int n, vector<vector<int>> wires) {
//     int answer = n;
//     vector<vector<int>> trees(n + 1);
    
//     for(auto wire: wires)
//     {
//         int u = wire[0], v = wire[1];
//         trees[u].push_back(v);
//         trees[v].push_back(u);
//     }
    
//     for(auto wire: wires)
//     {
//         int u = wire[0], v = wire[1];
        
//         //int cnt1 = countNode(u, v, trees);
//         //int cnt2 = countNode(v, u, trees);
        
//         //answer = min(abs(cnt1 - cnt2), answer);
//         int cnt = countNode(u, v, trees);
//         answer = min(abs(n - 2 * cnt), answer);
//     }
    
//     return answer;
    
    vector<int> parent(n + 1), subtree(n + 1);
    vector<vector<int>> tree(n + 1);
    
    for(auto& wire: wires)
    {
        int u = wire[0], v = wire[1];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    dfs(1, 0, tree, parent, subtree);
    
    int answer = n;
    for(auto& wire: wires)
    {
        int u = wire[0], v = wire[1];
        int child = (parent[u] == v) ? u : v;

        answer = min(answer, abs(2 * subtree[child] - n));
    }
    
    return answer;
}
