#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    
    for(int x: arr)
    {
        if(stk.empty() || stk.back() != x) stk.push_back(x);
        else stk.pop_back();
    }
    
    if(stk.empty()) stk.push_back(-1);
    
    return stk;
}
