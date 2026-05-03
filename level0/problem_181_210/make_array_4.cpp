#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int i = 0;
    int size = arr.size();
    vector<int> stk;
    
    while(i < size)
    {
        if(stk.empty() || stk.back() < arr[i]) 
        {
            stk.push_back(arr[i]);
            i++;
        }
        else if(stk.back() >= arr[i])
            stk.pop_back();
    }
    
    return stk;
}
