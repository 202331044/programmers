#include <string>
#include <vector>

using namespace std;

void dfs(int size, int r, int c, vector<vector<int>>& arr, vector<int>& answer)
{
    int num = arr[r][c];
   
    for(int i = r; i < r + size; ++i)
    {
        for(int j = c; j < c + size; ++j)
        {
            if(num != arr[i][j])
            {
                int half = size / 2;
                dfs(half, r, c, arr, answer);
                dfs(half, r, c + half, arr, answer);
                dfs(half, r + half, c, arr, answer);
                dfs(half, r + half, c + half, arr, answer);
                return;
            }
        }
    }
    
    answer[num]++;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    dfs(arr.size(), 0, 0, arr, answer);
    
    return answer;
}
