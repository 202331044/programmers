#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    const int MOD = 1000000007;
    
    vector<vector<int>> count(n, vector<int>(m, 0));
    count[0][0] = 1;
    
    for(const auto& p: puddles)
    {
        int x = p[0] - 1;
        int y = p[1] - 1;
        
        count[y][x] = -1;
    }
    
    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < m; ++x)
        {
            if(count[y][x] != 0) continue;
            
            int dx = (x - 1 >= 0) ? count[y][x - 1] : 0;
            int dy = (y - 1 >= 0) ? count[y - 1][x] : 0;
            
            dx = (dx < 0) ? 0 : dx;
            dy = (dy < 0) ? 0 : dy;
            
            count[y][x] = (dx + dy) % MOD;
        }
    }

    return count[n - 1][m - 1];
}
