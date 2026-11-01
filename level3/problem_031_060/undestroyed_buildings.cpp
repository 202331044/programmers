#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
//     int h = board.size();
//     int w = board[0].size();
    
//     for(const auto& sk: skill)
//     {
//         int type = sk[0];
//         int r1 = sk[1];
//         int c1 = sk[2];
//         int r2 = sk[3];
//         int c2 = sk[4];
//         int degree = sk[5];
        
//         if(type == 1) degree = -degree;
        
//         for(int r = r1; r <= r2; ++r)
//             for(int c = c1; c <= c2; ++c)
//                 board[r][c] += degree;
//     }
    
//     int answer = 0;
    
//     for(int r = 0; r < h; ++r)
//         for(int c = 0; c < w; ++c)
//             if(board[r][c] > 0) answer++;

//     return answer;
    
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<int>> diff(n + 1, vector<int>(m + 1));
    
    for(const auto& s: skill)
    {
        int type = s[0];
        int r1 = s[1], c1 = s[2];
        int r2 = s[3], c2 = s[4];
        int degree = s[5];
        
        if(type == 1) degree = -degree;
        
        diff[r1][c1] += degree;
        diff[r1][c2 + 1] -= degree;
        diff[r2 + 1][c1] -= degree;
        diff[r2 + 1][c2 + 1] += degree;  
    }
    
    for(int r = 0; r < n; ++r)
        for(int c = 1; c < m; ++c)
            diff[r][c] += diff[r][c - 1];
    
    for(int c = 0; c < m; ++c)
        for(int r = 1; r < n; ++r)
            diff[r][c] += diff[r - 1][c];
      
    int answer = 0;
    
    for(int r = 0; r < n; ++r)
        for(int c = 0; c < m; ++c)
            if(board[r][c] + diff[r][c] > 0) answer++;
    
    return answer;

}
