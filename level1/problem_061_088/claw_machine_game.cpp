#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    
    stack<int> s;
    
    for(const int& move: moves)
    {
        for(int i = 0; i < n; ++i)
        {   
            if(board[i][move - 1] == 0) continue;

            if(!s.empty() && s.top() == board[i][move - 1])
            {
                s.pop();
                answer += 2;
            }          
            else
                s.push(board[i][move-1]);
            
            board[i][move - 1] = 0;
            
            break;
        }
    }
    
    return answer;
}
