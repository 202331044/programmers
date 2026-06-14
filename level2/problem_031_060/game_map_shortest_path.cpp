#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int h = maps.size();
    int w = maps[0].size();
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    
    queue<pair<int, int>> que;
    queue<int> count;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    
    que.push({0, 0});
    count.push(1);
    visited[0][0] = true;
    
    while(!que.empty())
    {
        auto[r, c] = que.front();
        int cnt = count.front();
        
        que.pop();
        count.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr >= 0 && nr < h && nc >= 0 && nc < w &&
               maps[nr][nc] == 1 && visited[nr][nc] == false)  
            {
                if(nr == h - 1 && nc == w - 1) 
                    return cnt + 1;
                
                visited[nr][nc] = true;
                que.push({nr, nc});
                count.push(cnt + 1);
            }
        }
    }
    
    return -1;
}
