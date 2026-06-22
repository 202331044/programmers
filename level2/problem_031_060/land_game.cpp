#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    int rows = land.size();
    
    for(int r = 1; r < rows; ++r)
    {
        for(int i = 0; i < 4; ++i)
        {
            int best =  - 1;
            for(int j = 0; j < 4; ++j)
            {
                if(i == j) continue;
                best = max(land[r-1][j], best);
            }
            
            land[r][i] += best;
        }
    }
    
    return max({land[rows - 1][0], land[rows - 1][1], 
                land[rows - 1][2], land[rows - 1][3]});
}
