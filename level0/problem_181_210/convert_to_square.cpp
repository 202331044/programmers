#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int row = arr.size(), col = arr[0].size();
    
    if(row < col)
    {
        vector<int> tmp(col, 0);
        arr.insert(arr.end(), (col - row), tmp);
    }
    else if(col < row)
    {
        for(int i = 0; i < row; ++i)
            arr[i].insert(arr[i].end(), row - col, 0);
    }

    return arr;
}
