#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// int calc_cycle(int r, int c, int dir, 
//                const vector<string>& grid,
//                vector<vector<vector<int>>>& dist)
// {
//     int h = grid.size();
//     int w = grid[0].size();
    
//     int nr = r;
//     int nc = c;
//     int ndir = dir;
    
//     while(true)
//     {
//         if(grid[r][c] == 'S')
//         {
//             if(dir == 0) nr++;
//             else if(dir == 1) nc--;
//             else if(dir == 2) nr--;
//             else nc++;
//         }
//         else if(grid[r][c] == 'L')
//         {
//             if(dir == 0) 
//             {
//                 nc++;
//                 ndir = 3;
//             }
//             else if(dir == 1) 
//             {
//                 nr++;
//                 ndir = 0;
//             }
//             else if(dir == 2) 
//             {
//                 nc--;
//                 ndir = 1;
//             }
//             else 
//             {
//                 nr--;
//                 ndir = 2;
//             }
//         }
//         else
//         {
//             if(dir == 0) 
//             {
//                 nc--;
//                 ndir = 1;
//             }
//             else if(dir == 1) 
//             {
//                 nr--;
//                 ndir = 2;
//             }
//             else if(dir == 2) 
//             {
//                 nc++;
//                 ndir = 3;
//             }
//             else 
//             {
//                 nr++;
//                 ndir = 0;
//             }
//         }
        
//         if(nr >= h) nr = 0;
//         if(nc >= w) nc = 0;
//         if(nr < 0) nr = h - 1;
//         if(nc < 0) nc = w - 1;
        
//         if(dist[nr][nc][ndir] != 0) 
//             return dist[nr][nc][ndir] + dist[r][c][dir] - 1;
        
//         dist[nr][nc][ndir] = dist[r][c][dir] + 1;
        
//         r = nr;
//         c = nc;
//         dir = ndir;
//     } 
// }

vector<int> solution(vector<string> grid) {
    
    int h = grid.size();
    int w = grid[0].size();
    
//     vector<vector<vector<int>>> dist(h, 
//                                      vector<vector<int>>(w, 
//                                      vector<int>(4, 0)));
//     vector<int> answer;
    
//     for(int r = 0; r < h; ++r)
//         for(int c = 0; c < w; ++c)
//             for(int dir = 0; dir < 4; ++dir)
//                 if(dist[r][c][dir] == 0)
//                     answer.push_back(calc_cycle(r, c, dir, grid, dist));
    
//     sort(answer.begin(), answer.end());
    
    vector<vector<vector<bool>>> visited(h, 
                                         vector<vector<bool>>(w, 
                                         vector<bool>(4, false)));
    
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, -1, 0, 1};
    
    vector<int> answer;
    
    for(int r = 0; r < h; ++r)
    {
        for(int c = 0; c < w; ++c)
        {
            for(int dir = 0; dir < 4; ++dir)
            {
                if(visited[r][c][dir]) continue;
                
                int nr = r;
                int nc = c;
                int ndir = dir;
                int len = 0;
                
                while(!visited[nr][nc][ndir])
                {
                    visited[nr][nc][ndir] = true;
                    len++;
                    
                    if(grid[nr][nc] == 'L')
                        ndir = (ndir + 3) % 4;
                    else if(grid[nr][nc] == 'R')
                        ndir = (ndir + 1) % 4;
                    
                    nr += dr[ndir];
                    nc += dc[ndir];

                    if(nr >= h) nr = 0;
                    if(nc >= w) nc = 0;
                    if(nr < 0) nr = h - 1;
                    if(nc < 0) nc = w - 1;
                }
                
                answer.push_back(len);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
