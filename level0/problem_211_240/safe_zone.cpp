#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int rows = board.size(), cols = board[0].size();
    
    int dr[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    
    for(int r = 0; r < rows; ++r)
    {
        for(int c = 0; c < cols; ++c)
        {
            if(board[r][c] == 1)
            {
                for(int i = 0; i < 8; ++i)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                
                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 0)
                        board[nr][nc] = 2;
                }
            }
        }
    }
    
    int cnt = 0;
    
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            if(board[i][j] == 0) cnt++;

    return cnt;
}
