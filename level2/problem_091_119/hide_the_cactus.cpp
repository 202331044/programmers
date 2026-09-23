#include <string>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
//     const int INF = m * n + 1;
//     vector<vector<int>> orders(m, vector<int>(n, 0));
    
//     for(int i = 0; i < drops.size(); ++i)
//     {
//         int r = drops[i][0];
//         int c = drops[i][1];
        
//         orders[r][c] = i + 1;
//     }
    
//     int ansR = 0,ansC = 0;
//     int answer = 0;
    
//     for(int r = 0; r <= m - h; ++r)
//     {
//         for(int c = 0; c <= n - w; ++c)
//         {
//             int minVal = INF;
            
//             for(int nr = r; nr < r + h; ++nr)
//                 for(int nc = c; nc < c + w; ++nc)
//                     if(orders[nr][nc] != 0 && minVal > orders[nr][nc])
//                         minVal = orders[nr][nc];
    
//             if(answer < minVal)
//             {
//                 answer = minVal;
//                 ansR = r;
//                 ansC = c;
//             }
            
//             if(answer == INF) return {ansR, ansC};
//         }
//     }
    
//     return {ansR, ansC};
    
    const int INF = m * n + 1;
    vector<vector<int>> rain(m, vector<int>(n, INF));
    
    for(int i = 0; i < drops.size(); ++i)
    {
        int r = drops[i][0];
        int c = drops[i][1];
        
        rain[r][c] = i + 1;
    }
    
    vector<vector<int>> row_min(m);
    
    for(int r = 0; r < m; ++r)
    {
        deque<pair<int, int>> dq;
        
        for(int c = 0; c < n; ++c)
        { 
            while(!dq.empty() && dq.back().first >= rain[r][c])
                dq.pop_back();

            dq.push_back({rain[r][c], c});
            
            while(c - dq.front().second >= w) 
                dq.pop_front();

            if(c >= w - 1)
                row_min[r].push_back(dq.front().first); 
        }
    }
    
    vector<int> pos = {0, 0};
    int answer = 0;
    
    for(int c = 0; c < row_min[0].size(); ++c)
    {
        deque<pair<int, int>> dq;
        
        for(int r = 0; r < m; ++r)
        { 
            while(!dq.empty() && dq.back().first >= row_min[r][c])
                dq.pop_back();

            dq.push_back({row_min[r][c], r});
            
            while(r - dq.front().second >= h) 
                dq.pop_front();

            if(r >= h - 1)
            {
                if(answer < dq.front().first ||
                  (answer == dq.front().first &&
                  (r - h + 1 < pos[0] || 
                  (r - h + 1 == pos[0] && c < pos[1]))))
                {
                    answer = dq.front().first;
                    pos[0] = r - h + 1;
                    pos[1] = c;
                }  
            }
        }
    }

    return pos;      
}
