#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;

    for(auto& query: queries)
    {
        int result = -1;
        int s = query[0], e = query[1], k = query[2];
        
        for(int i = s; i <= e; ++i)
        {
            if(k < arr[i]) 
            {
                if(result == -1) result = arr[i];
                else result = arr[i] < result ? arr[i] : result;
            }
        }
        answer.push_back(result);
    }
    
    return answer;
}
