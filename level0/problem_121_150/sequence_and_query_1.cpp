#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(auto op: queries)
    {
        int s = op[0], e = op[1];
        
        for(int i = s; i <= e; ++i) arr[i]++;
    }
    
    return arr;
}
