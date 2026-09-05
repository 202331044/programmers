#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int r, int c, vector<vector<int>>& picture)
{
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    
    queue<pair<int, int>> que;
    que.push({r, c});

    int size = 0;
    int color = picture[r][c];
    
    picture[r][c] = 0;
    
    while(!que.empty())
    {
        auto [cr, cc] = que.front();
        que.pop();
        size++;
        
        for(int i = 0; i < 4; ++i)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(nr >= 0 && nr < picture.size() && 
               nc >= 0 && nc < picture[0].size() &&
               picture[nr][nc] == color)
            {
                picture[nr][nc] = 0;
                que.push({nr, nc});
            }
        }
    }
    
    return size;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int r = 0; r < m; ++r)
    {
        for(int c = 0; c < n; ++c)
        {
            if(picture[r][c] != 0)
            {
                max_size_of_one_area = max(max_size_of_one_area, 
                                           bfs(r, c, picture));
                number_of_area++;
            }
                
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}
