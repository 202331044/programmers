#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
//     const int size = 101;
//     vector<vector<unordered_map<int, int>>> maps(size, 
//                                                  vector<unordered_map<int, int>>(size));
    
//     int answer = 0;
    
//     for(auto& route: routes)
//     {
//         int r = points[route[0] - 1][0] - 1;
//         int c =  points[route[0] - 1][1] - 1;
//         int t = 0;
        
//         for(int i = 1; i < route.size(); ++i)
//         {
//             int nextr = points[route[i] - 1][0] - 1;
//             int nextc = points[route[i] - 1][1] - 1;
//             int dc = 0;
//             int dr = 0;
            
//             if(c < nextc) dc = 1;
//             else if (c > nextc) dc = -1;
            
//             if(r < nextr) dr = 1;
//             else if (r > nextr) dr = -1;
            
//             while(true)
//             {
//                 maps[r][c][t]++;
//                 if(maps[r][c][t] == 2) answer++;
//                 t++;
                
//                 if(r != nextr) r += dr;
//                 else c += dc;
                
//                 if(r == nextr && c == nextc) break;
//             }       
//         }
        
//         maps[r][c][t]++;
//         if(maps[r][c][t] == 2) answer++;
//         t++;
//     }
    
//     return answer;
    
    vector<vector<pair<int, int>>> records;
    int maxTime = 0;
    
    for(auto& route: routes)
    {
        int r = points[route[0] - 1][0];
        int c =  points[route[0] - 1][1];
        
        vector<pair<int, int>> tmp;
        
        for(int i = 1; i < route.size(); ++i)
        {
            int nextr = points[route[i] - 1][0];
            int nextc = points[route[i] - 1][1];
            int dc = 0;
            int dr = 0;
            
            if(r < nextr) dr = 1;
            else if(r > nextr) dr = -1;
            
            if(c < nextc) dc = 1;
            else if(c > nextc) dc = -1;
            
            while(true)
            {
                tmp.push_back({r, c});
                
                if(r != nextr) r += dr;
                else c += dc;
                
                if(r == nextr && c == nextc) break;
            }       
        }
        
        tmp.push_back({r, c});
        maxTime = max(maxTime, (int)tmp.size());
        records.push_back(tmp);
    }
    
    int answer = 0;
    
    for(int t = 0; t < maxTime; ++t)
    {
        vector<vector<int>> cnt(101, vector<int>(101, 0));
        for(int x = 0; x < records.size(); ++x)
        {
            if(records[x].size() > t)
            {
                int r = records[x][t].first;
                int c = records[x][t].second;
                
                cnt[r][c]++;
                if(cnt[r][c] == 2) answer++;
            }
        }
    }
    
    return answer;
}
