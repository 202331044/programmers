#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(const int r, const int c, const vector<string>& maps, 
         vector<vector<bool>>& visited)
{
    int days = 0;
    queue<pair<int, int>> que;
    que.push({r, c});
    visited[r][c] = true;
    
    int dr[4] = {1, 0, 0, -1};
    int dc[4] = {0, 1, -1, 0};
    
    while(!que.empty())
    {
        auto [cr, cc] = que.front();
        days += maps[cr][cc] - '0';
        que.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(nr >= 0 && nr < maps.size() && nc >= 0 &&
               nc < maps[0].size() && maps[nr][nc] != 'X' &&
               visited[nr][nc] == false)
            {
                visited[nr][nc] = true;
                que.push({nr, nc});
            }
        }
    }
    
    return days;
}
vector<int> solution(vector<string> maps) {
    int row = maps.size();
    int col = maps[0].size();
    
    vector<int> answer;
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            if(maps[i][j] == 'X' || visited[i][j]) continue;
            answer.push_back(bfs(i, j, maps, visited));
        }
    }
    
    if(answer.empty()) answer.push_back(-1);
    
    sort(answer.begin(), answer.end());
    return answer;
}
