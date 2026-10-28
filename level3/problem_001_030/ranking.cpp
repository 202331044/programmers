#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(
    const int start,
    const vector<vector<int>>& routes,
    vector<int>& parent
)
{
    queue<int> que;
    que.push(start);
    
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        
        for(int next: routes[cur])
        {
            if(parent[next]) continue;

            parent[next] = parent[cur];
            que.push(next);
        }
    }
}

int solution(int n, vector<vector<int>> results) {
//     vector<vector<int>> out(n + 1);
//     vector<vector<int>> in(n + 1);
    
//     for(const auto& result: results)
//     {
//         int u = result[0];
//         int v = result[1];
        
//         out[u].push_back(v);
//         in[v].push_back(u);
//     }
    
//     int answer = 0;
//     for(int i = 1; i <= n; ++i)
//     {
//         vector<int> parent_out(n + 1);
//         vector<int> parent_in(n + 1);
        
//         parent_out[i] = i;
//         parent_in[i] = i;
        
//         bfs(i, out, parent_out);
//         bfs(i, in, parent_in);
        
//         int cnt = 0;
//         for(int j = 1; j <= n; ++j)
//             if(parent_out[j] == i || parent_in[j] == i)
//                 cnt++;

//         if(cnt == n) answer++;
//     }
    
//     return answer;
    
    vector<vector<bool>> win(n + 1, vector<bool>(n + 1, false));
    for(const auto& result: results)
    {
        int u = result[0];
        int v = result[1];
        win[u][v] = true;
    }
    
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(win[i][k] && win[k][j])
                    win[i][j] = true;
    
    int answer = 0;
    for(int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        for(int j = 1; j <= n; ++j)
            if(win[i][j] || win[j][i])
                cnt++;
        
        if(cnt == n - 1) answer++;
    }
    
    return answer;
}
