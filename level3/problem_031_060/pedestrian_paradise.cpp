#include <vector>

using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<vector<int>>> routes(
        m, vector<vector<int>>(n, vector<int>(2, 0))
    );
    
    routes[0][0] = {1, 1};
    
    for(int r = 0; r < m; ++r)
    {
        for(int c = 0; c < n; ++c)
        {
            if(city_map[r][c] == 1) continue;
            
            int nr = r - 1;
            int nc = c;

            if(nr >= 0)
            {
                if(city_map[nr][nc] == 2 || (nr == 0 && nc == 0))
                    routes[r][c][0] = routes[nr][nc][0];
                else
                    routes[r][c][0] = (routes[nr][nc][0] + routes[nr][nc][1]) % MOD;
            }
                
            nr = r;
            nc = c - 1;
            
            if(nc >= 0)
            {
                if(city_map[nr][nc] == 2 || (nr == 0 && nc == 0))
                    routes[r][c][1] = routes[nr][nc][1];
                else
                    routes[r][c][1] = (routes[nr][nc][0] + routes[nr][nc][1]) % MOD;
            }
        }
    }

    return (routes[m - 1][n - 1][0] + routes[m - 1][n - 1][1]) % MOD;
}
