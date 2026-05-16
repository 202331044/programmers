#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int rows = arr1.size(), cols = arr1[0].size();
    
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            arr1[i][j] += arr2[i][j];

    return arr1;
}
