#include <string>
#include <vector>

using namespace std;

int dr[4][4] = {{0, 0, 0, 0},
                {1, 2, -1, -2},
                {1, 2, -1, -2},
                {1, 2, -1, -2}};

int dc[4][4] = {{1, 2, -1, -2},
                {0, 0, 0, 0},
                {1, 2, -1, -2},
                {-1, -2, 1, 2}};

bool isWin(const int r, const int c, const vector<string>& board)
{
    char ch = board[r][c];

    for(int i = 0; i < 4; ++i)
    {
        int same = 1;
        
        for(int j = 0; j < 4; ++j)
        {
            int nr = r + dr[i][j];
            int nc = c + dc[i][j];
            
            if(nr >= 0 && nr < board.size() && 
               nc >= 0 && nc < board.size() &&
               board[nr][nc] == ch)
                same++;
        }
        
        if(same == 3) return true;
    }
    
    return false;
}

int solution(vector<string> board) {
    int cntO = 0;
    int cntX = 0;
    bool winO = false;
    bool winX = false;
    
    for(int r = 0; r < board.size(); ++r)
    {
        for(int c = 0; c < board[r].size(); ++c)
        {
            if(board[r][c] == 'O') 
            {
                cntO++;
                if(isWin(r, c, board)) winO = true;
            }
            else if(board[r][c] == 'X') 
            {
                cntX++;
                if(isWin(r, c, board)) winX = true;
            }  
        }
    }
    
    if(cntX > cntO || cntO > cntX + 1) return 0;
    if(winX == true && winO == true) return 0;
    if(cntO <= cntX && winO == true) return 0;
    if(cntO > cntX && winX == true) return 0;
    return 1;
    
}
