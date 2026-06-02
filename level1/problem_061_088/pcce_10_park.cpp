#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int checkSquare(vector<vector<string>>& park, int r, int c, int h, int w)
{
    vector<vector<int>> visited(h, vector<int>(w, 0));
    int dr[3] = {1, 1, 0};
    int dc[3] = {0, 1, 1};
    
    queue<pair<int, int>> que;
    queue<int> num;
    
    que.push({r, c});
    num.push(1);
    visited[r][c] = 1;
       
    int answer = 0;
    
    while(!que.empty())
    {
        auto[cr, cc] = que.front();
        answer = num.front();
        
        que.pop();
        num.pop();
        
        for(int k = 0; k < 3; ++k)
        {
            int nr = cr + dr[k];
            int nc = cc + dc[k];
            
            if(nr < h && nc < w)
            {
                if(park[nr][nc] == "-1")
                {
                    if(visited[nr][nc] == 0)
                    {
                        visited[nr][nc] = 1;
                        que.push({nr, nc});
                        num.push(answer + 1);
                    }
                }        
                else
                    return answer;
            }
            else
                return answer;
        }  
    }
    
    return answer;
}

int solution(vector<int> mats, vector<vector<string>> park) {
//    int maxSize = -1;
    int h = park.size();
    int w = park[0].size();
    
//     for(int r = 0; r < h; ++r)
//     {
//         for(int c = 0; c < w; ++c)
//         {
//             if(park[r][c] == "-1")
//                 maxSize = max(maxSize, checkSquare(park, r, c, h, w));   
//         }
//     }
    
//     int answer = -1;
//     for(int size: mats)
//     {
//         if(size <= maxSize) 
//             answer = max(answer, size);
//     }
    
//     return answer;
    
    int dr[3] = {-1, -1, 0};
    int dc[3] = {0, -1, -1};
    vector<vector<int>> dp(h, vector<int>(w, 0));
    
    int maxSize = 0;
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            if(park[i][j] != "-1") continue;
            
            if(i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + 1;
            maxSize = max(maxSize, dp[i][j]);
        }
    }
    
    
    int answer = -1;
    for(int size: mats)
    {
        if(size <= maxSize) 
            answer = max(size, answer);
    }
    
    return answer;
}
