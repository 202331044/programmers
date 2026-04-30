#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(auto query: queries)
    {
        int i = query[0], j = query[1];
        swap(arr[i], arr[j]);
    }
           
    return arr;
}
