#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int h = board.size();
    int w = board[0].size();

    for(int i = 1; i < h; ++i)
        for(int j = 1; j < w; ++j)
            if(board[i][j] == 1)
                board[i][j] = min({board[i][j - 1], 
                                   board[i - 1][j], 
                                   board[i - 1][j - 1]}) + 1;

    int answer = 0;
    
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
            if(board[i][j] > answer) answer = board[i][j];
    
    return answer * answer;

}
