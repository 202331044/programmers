#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
//     int k = info.size();
    
//     vector<vector<int>> vec(k + 1, vector<int>(m, n));
    
//     for(int i = 0; i < m; ++i)
//         vec[0][i] = 0;
    
//     for(int i = 0; i < k; ++i)
//     {
//         int a = info[i][0];
//         int b = info[i][1];
        
//         for(int j = 0; j < m; ++j)
//         {
//             if(j + b < m) vec[i + 1][j + b] = vec[i][j];
//             vec[i + 1][j] = min(vec[i + 1][j], vec[i][j] + a);
//         } 
//     }
    
//     int answer = n;
//     for(int i = 0; i < m; ++i)
//          answer = min(answer, vec[k][i]);

//     if(answer == n) return -1;
//     return answer;
    
    int k = info.size();
    vector<vector<int>> vec(k + 1, vector<int>(m, n));
    vec[0][0] = 0;
    
    for(int i = 0; i < k; ++i)
    {
        int a = info[i][0];
        int b = info[i][1];
        
        for(int j = 0; j < m; ++j)
        {
            if(vec[i][j] == n) continue;
            
            if(j + b < m)
                vec[i + 1][j + b] = min(vec[i + 1][j + b], vec[i][j]);
            
            if(vec[i][j] + a < n)
                vec[i + 1][j] = min(vec[i + 1][j], vec[i][j] + a);
        }
    }
    
    int answer = n;
    
    for(int i = 0; i < m; ++i)
        answer = min(answer, vec[k][i]);
    
    if(answer == n) return -1;
    return answer;
}
