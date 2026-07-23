#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

void get_start(queue<pair<int, int>>& que, vector<vector<int>>& dist, 
               vector<string>& board)
{
    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[0].size(); ++j)
        {
            if(board[i][j] == 'R')
            {
                que.push({i, j});
                dist[i][j]++;
                return;
            }
        }
    }
}

int solution(vector<string> board) {
//     int h = board.size(), w = board[0].size();
    
//     vector<vector<bool>> visited(h, vector<bool>(w, false));
//     queue<tuple<int, int, int>> que;

//     for(int i = 0; i < h; ++i)
//     {
//         for(int j = 0; j < w; ++j)
//         {
//             if(board[i][j] == 'R')
//             {
//                 que.push({0, i, j});
//                 visited[i][j] = true;
//                 break;
//             }
//         }
//     }
    
    
//     int dr[4] = {1, 0, 0, -1};
//     int dc[4] = {0, 1, -1, 0};
    
//     while(!que.empty())
//     {
//         auto[cnt, r, c] = que.front();
//         que.pop();
        
//         for(int i = 0; i < 4; ++i)
//         {
//             int nr = r;
//             int nc = c;
            
//             while(nr >= 0 && nr < h && nc >= 0 && nc < w &&
//                   board[nr][nc] != 'D')
//             {
//                 nr += dr[i];
//                 nc += dc[i];
//             }
            
//             nr -= dr[i];
//             nc -= dc[i];
            
//             if(board[nr][nc] == 'G') 
//                 return cnt + 1;
            
//             if(visited[nr][nc] == false)
//             {
//                 que.push({cnt + 1, nr, nc});
//                 visited[nr][nc] = true;
//             }     
//         }
//     }
    
//     return -1;
    
    int h = board.size();
    int w = board[0].size();
    
    queue<pair<int, int>> que;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    
    get_start(que, dist, board);
              
    int dr[4] = {1, 0, 0, -1};
    int dc[4] = {0, 1, -1, 0};
    
    while(!que.empty())
    {
        auto [r, c] = que.front();
        que.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            int nr = r;
            int nc = c;

            while(nr >= 0 && nr < h && nc >= 0 && nc < w &&
                  board[nr][nc] != 'D')
            {
                nr += dr[i];
                nc += dc[i];
            }

            nr -= dr[i];
            nc -= dc[i];
            
            if(board[nr][nc] == 'G') 
                return dist[r][c] + 1;

            if(dist[nr][nc] == -1)
            {
                que.push({nr, nc});
                dist[nr][nc] = dist[r][c] + 1;
            }     
        }
    }
    
    return -1;
}
