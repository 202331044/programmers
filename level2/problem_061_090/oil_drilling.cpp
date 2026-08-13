#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

// void bfs(const int idx, const int r, const int c, 
//          vector<vector<int>>& land, vector<vector<int>>& visited)
// {
//     int h = land.size();
//     int w = land[0].size();
    
//     queue<pair<int, int>> pos, que;
//     que.push({r, c});
//     visited[r][c] = idx;
    
//     int dr[4] = {1, -1, 0, 0};
//     int dc[4] = {0, 0, 1, -1};
    
//     while(!que.empty())
//     {
//         auto [cr, cc] = que.front();
//         pos.push({cr, cc});
//         que.pop();
        
//         for(int i = 0; i < 4; ++i)
//         {
//             int nr = cr + dr[i];
//             int nc = cc + dc[i];
            
//             if(nr >= 0 && nr < h && nc >= 0 && nc < w && 
//                land[nr][nc] == 1 && visited[nr][nc] != idx)
//             {
//                 que.push({nr, nc});
//                 visited[nr][nc] = idx;
//             }
//         }
//     }
    
//     int cnt = pos.size();
//     while(!pos.empty())
//     {
//         auto [cr, cc] = pos.front();
//         pos.pop();
        
//         land[cr][cc] = cnt;
//     }
// }

int bfs2(const int idx, const int r, const int c, 
          vector<vector<int>>& land, vector<vector<int>>& board)
{
    
    int n = land.size();
    int m = land[0].size();
    
    queue<pair<int, int>> que;
    que.push({r, c});
    board[r][c] = idx;
    
    int cnt = 0;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    
    while(!que.empty())
    {
        auto [cr, cc] = que.front();
        que.pop();
        cnt++;
        
        for(int i = 0; i < 4; ++i)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < m 
               && land[nr][nc] == 1 && board[nr][nc] == 0)
            {
                que.push({nr, nc});
                board[nr][nc] = idx;
            }
        }
    }
    
    return cnt;
}
int solution(vector<vector<int>> land) {
//     int h = land.size();
//     int w = land[0].size();
//     vector<vector<int>> visited(h, vector<int>(w, 0));
    
//     int idx = 1;
//     for(int r = 0; r < h; ++r)
//         for(int c = 0; c < w; ++c)
//             if(land[r][c] == 1 && visited[r][c] == 0)
//                 bfs(idx++, r, c, land, visited);

//     int answer = 0;

//     for(int c = 0; c < w; ++c)
//     {
//         unordered_set<int> s;
//         int sum = 0;
        
//         for(int r = 0; r < h; ++r)
//         {
//             if(land[r][c] != 0 && s.find(visited[r][c]) == s.end())
//             {
//                 sum += land[r][c];
//                 s.insert(visited[r][c]);
//             }
//         }
//         answer = max(sum, answer);
//     }
    
//     return answer;
    
    int n = land.size();
    int m = land[0].size();
    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<int> component_size;
    
    int idx = 1;
    for(int r = 0; r < n; ++r)
        for(int c = 0; c < m; ++c)
            if(land[r][c] == 1 && board[r][c] == 0)
                component_size.push_back(bfs2(idx++, r, c, land, board));    
    
    int answer = 0;
    for(int c = 0; c < m; ++c)
    {
        unordered_set<int> s;
        int sum = 0;
        
        for(int r = 0; r < n; ++r)
        {
            int id = board[r][c];
            
            if(id > 0 && s.find(id) == s.end())
            {
                sum += component_size[id - 1];
                s.insert(id);
            }
        }
        
        answer = max(answer, sum);
    }
    
    return answer;
}
