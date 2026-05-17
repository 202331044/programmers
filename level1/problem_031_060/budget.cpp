#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    
//     for(int i = 0; i < d.size(); ++i)
//     {
//         if(budget - d[i] < 0) return i;
//         else if(budget - d[i] == 0) return i + 1;
//         budget -= d[i];
//     }
    
//     return d.size();
    
    int cnt = 0;
    
    for(int cost: d)
    {
        if(budget < cost) break;
        budget -= cost;
        cnt++;
    }
    
    return cnt;
}
