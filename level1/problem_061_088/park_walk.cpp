#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int h = park.size();
    int w = park[0].size();
    
    int x, y;
    bool isStop = false;
        
    for(int r = 0; r < h; ++r)
    {
        for(int c = 0; c < w; ++c)
        {
            if(park[r][c] == 'S')
            {
                y = r;
                x = c;
                isStop = true;
                break;
            }
        }
        if(isStop) break;
    }
    
    int dx[128] = {};
    int dy[128] = {}; 
    dx['E'] = 1;
    dx['W'] = -1;
    dy['S'] = 1;
    dy['N'] = -1;
    
    for(const string& route: routes)
    {
        char op = route[0];
        int dist = route[2] - '0';
        
        int cx = x;
        int cy = y;
        
        for(int i = 1; i <= dist; ++i)
        {
            cx += dx[op];
            cy += dy[op];
            
            if(cx < 0 || cx >= w || cy < 0 || cy >= h || park[cy][cx] == 'X')
            {
                cx = x;
                cy = y;
                break;
            }
        }
        
        x = cx;
        y = cy;
    }
    
    return {y, x};
}
