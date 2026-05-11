#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    for(int i = 0; i < query.size(); ++i)
    {
        vector<int> answer;
        if(i % 2 == 0)
        {
            int e = query[i];
            // for(int i = 0; i <= e; ++i)
            //     answer.push_back(arr[i]);
            arr = vector<int>(arr.begin(), arr.begin() + e + 1);
        }
        else
        {
            int s = query[i];
            // for(int i = s; i < arr.size(); ++i)
            //     answer.push_back(arr[i]);
            arr = vector<int>(arr.begin() + s, arr.end());
        }
        //arr = answer;
    }
    return arr;
}
