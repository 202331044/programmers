#include <string>
#include <vector>
#include <cmath>

using namespace std;

void dfs(int& answer, const int n, const int row, vector<pair<int, int>>& pos)
{
    if(row == n)
    {
        answer++;
        return;
    }
    
    for(int col = 0; col < n; ++col)
    {
        bool isValid = true;
        
        for(const auto& [r, c]: pos)
        {
            if(row == r) return;
            if((col == c) || (abs(row - r) == abs(col - c)))
            {
                isValid = false;
                break;
            }
        }
        
        if(isValid)
        {
            pos.push_back({row, col});
            dfs(answer, n, row + 1, pos);
            pos.pop_back();
        }
    }
}

void dfs2(int& answer, const int n, const int row, vector<int>& pos)
{
    if(row == n)
    {
        answer++;
        return;
    }
    
    for(int col = 0; col < n; ++col)
    {
        bool isValid = true;
        
        for(int r = 0; r < row; ++r)
        {
            if((col == pos[r]) || (abs(col - pos[r]) == abs(row - r)))
            {
                isValid = false;
                break;
            }
        }
        
        if(isValid)
        {
            pos.push_back(col);
            dfs2(answer, n, row + 1, pos);
            pos.pop_back();
        }
    }
}

int solution(int n) {
    int answer = 0;
//     vector<pair<int, int>> pos;
    
//     dfs(answer, n, 0, pos);
    
    vector<int> pos;
    dfs2(answer, n, 0, pos);
    
    return answer;
}
