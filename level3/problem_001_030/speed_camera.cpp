#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), [](const auto& a, const auto& b)
         {
             return a[1] < b[1];
         });
    
    int answer = 0;
    int pos = -30001;
    
    for(const auto& route: routes)
    {
        int in = route[0];
        int out = route[1];
        
        if(pos >= in && pos <= out) continue;
        
        pos = out;
        answer++;
    }
    
    return answer;
}
