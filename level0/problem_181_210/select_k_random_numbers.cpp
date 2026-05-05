#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer(k, -1);
    unordered_set<int> s;
    
    int idx = 0;
    for(int num: arr)
    {
        if(s.count(num) == 0) 
        {
            answer[idx++] = num;
            s.insert(num);
            
            if(idx >= k) break;
        }
    }
    
    return answer;
}
