#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    unordered_map<int, int> um;
    unordered_set<int> us;
    int total = 0;
    
    for(int t: topping)
    {
        if(um[t] == 0)
            total++;
        
        um[t]++;
    }
     
    int answer = 0;
    for(int t: topping)
    {
        us.insert(t);
        um[t]--;
        
        if(um[t] == 0) total--;
        
        if(us.size() == total) answer++;
        else if(us.size() > total) return answer;
    }
    
    return answer;
}
