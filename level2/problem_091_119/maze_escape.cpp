#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> find_start_lever(vector<string>& maps)
{
    int h = maps.size();
    int w = maps[0].size();
    
    vector<int> points(4);
    
    int cnt = 0;
    
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            if(maps[i][j] == 'S')
            {
                points[0] = j;
                points[1] = i;
                cnt++;
            }
            else if(maps[i][j] == 'L')
            {
                points[2] = j;
                points[3] = i;
                cnt++;
            }
            
            if(cnt == 2) return points;
        }     
    }
}

int find_point(const int startX, const int startY, const char target,
               vector<string>& maps)
{
    int h = maps.size();
    int w = maps[0].size();
    
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pair<int, int>> que;
    dist[startY][startX] = 0;
    
    que.push({startX, startY});
    
    while(!que.empty())
    {
        auto [x, y] = que.front();
        que.pop();
       
        if(maps[y][x] == target) return dist[y][x];
        
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dc[i];
            int ny = y + dr[i];
            
            if(nx >= 0 && nx < w 
               && ny >= 0 && ny < h 
               && maps[ny][nx] != 'X' 
               && dist[ny][nx] == -1)
            {
                que.push({nx, ny});
                dist[ny][nx] = dist[y][x] + 1;
            }   
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    vector<int> points = find_start_lever(maps);
    
    int dist1 = find_point(points[0], points[1], 'L', maps);
    if(dist1 == -1) return -1;
    
    int dist2 = find_point(points[2], points[3], 'E', maps);
    if(dist2 == -1) return -1;
    
    return dist1 + dist2;
}
