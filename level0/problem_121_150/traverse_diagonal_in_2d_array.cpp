#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k) {
    int sum = 0;
    int h = board.size(), w = board[0].size();
    
//     for(int i = 0; i <= k; ++i)
//     {   
//         if(i >= h) break;
        
//         for(int j = 0; i + j <= k; ++j)
//         {
//             if(j >= w) break;
            
//             sum += board[i][j];
//         }
//     }
    
    for(int i = 0; i <= k && i < h; ++i)
        for(int j = 0; i + j <= k && j < w; ++j)
            sum += board[i][j];

    return sum;
}
