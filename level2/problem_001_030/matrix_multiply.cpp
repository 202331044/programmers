#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    
    int row = arr1.size();
    int inner = arr2.size();
    int col = arr2[0].size();
    
    vector<vector<int>> answer(row, vector<int>(col, 0));
    
    for(int r = 0; r < row; ++r)
    {
        for(int c = 0; c < col; ++c)
        {
            for(int i = 0; i < inner; ++i)
                answer[r][c] += arr1[r][i] * arr2[i][c];   
        }
    }
    
    return answer;
}
