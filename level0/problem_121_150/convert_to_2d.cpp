#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    int r = num_list.size()/n, c = n;
    int idx = 0;
    
    vector<vector<int>> answer(r, vector<int>(c));
    
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            answer[i][j] = num_list[idx++];
    
    return answer;
}
