#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    int pre = arr[0];
    vector<int> answer = {pre};
    
    for(int i = 1; i < arr.size(); ++i)
    {
        if(pre == arr[i]) continue;
        answer.push_back(arr[i]);
        
        pre = arr[i];
    }

    return answer;
}
