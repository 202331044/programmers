#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<string> board) {
//     int answer = 0;
//     int H = board.size();
//     int W = board[0].size();
    
//     while(true)
//     {
//         int dr[3] = {1, 1, 0};
//         int dc[3] = {0, 1, 1};
        
//         vector<vector<bool>> clear(H, vector<bool>(W, false));
//         for(int r = 0; r < H; ++r)
//         {
//             for(int c = 0; c < W; ++c)
//             {    
//                 if(board[r][c] == ' ') continue;
                
//                 int cnt = 0;
//                 for(int i = 0; i < 3; ++i)
//                 {
//                     int nr = r + dr[i];
//                     int nc = c + dc[i];
                    
//                     if(nr >= 0 && nr < H && nc >= 0 && nc < W 
//                        && board[nr][nc] == board[r][c])
//                         cnt++;
//                     else
//                         break;
//                 }
                
//                 if(cnt == 3)
//                 {
//                     clear[r][c] = true;
//                     for(int i = 0; i < 3; ++i)
//                         clear[r + dr[i]][c + dc[i]] = true;
//                 }     
//             }
//         }
        
//         int save = answer;
//         for(int c = 0; c < W; ++c)
//         {
//             int row = H - 1;
//             for(int r = H - 1; r >= 0; --r)
//             {
//                 if(clear[r][c] == true)
//                 {
//                     board[r][c] = ' ';
//                     answer++;
//                 }      
//                 else
//                     swap(board[row--][c], board[r][c]);
//             }
//         }
        
//         if(save == answer) 
//             return answer;
//     }
    
//     return answer;
    
    int answer = 0;

    while(true)
    {
        int removed = 0;
        vector<vector<bool>> mark(m, vector<bool>(n, false));
    
        for(int r = 0; r < m - 1; ++r)
        {
            for(int c = 0; c < n - 1; ++c)
            {
                if(board[r][c] == ' ') continue;

                if(board[r][c] == board[r + 1][c + 1] && 
                   board[r][c] == board[r + 1][c] &&
                   board[r][c] == board[r][c + 1])
                {
                    mark[r][c] = true;
                    mark[r + 1][c + 1] = true;
                    mark[r + 1][c] = true;
                    mark[r][c + 1] = true;
                }
            }
        }

        for(int c = 0; c < n; ++c)
        {
            int row = m - 1;
            for(int r = m - 1; r >= 0; --r)
            {
                if(mark[r][c])
                    removed++; 
                else
                    board[row--][c] = board[r][c];
            }

            while(row >= 0)
                board[row--][c] = ' ';
        }
        
        if(removed == 0) return answer;
        answer += removed;
        removed = 0;
    }
    
    return answer;
}
