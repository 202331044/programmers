#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int h = wallpaper.size(), w = wallpaper[0].size();
    int lux = h, luy = w, rdx = 0, rdy = 0;
    
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            if(wallpaper[i][j] == '#')
            {
                lux = min(lux, i);
                luy = min(luy, j);
                
                rdx = max(rdx, i);
                rdy = max(rdy, j);
            }
        }
    }
    
    return {lux, luy, rdx + 1, rdy + 1};
}
