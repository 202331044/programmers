#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    
//     unordered_map<int, int> um;
//     for(int t: tangerine)
//         um[t]++;
    
//     vector<pair<int, int>> vec;
//     for(auto& it: um)
//         vec.emplace(vec.end(), it.second, it.first);
    
//     sort(vec.begin(), vec.end(), greater<pair<int, int>>());
    
//     int total = 0;
//     for(int i = 0; i < vec.size(); ++i)
//     {
//         if(total + vec[i].first >= k) 
//             return i + 1;
        
//         total += vec[i].first;
//     }
    
    unordered_map<int, int> cnt;
    for(int t: tangerine)
        cnt[t]++;
    
    vector<int> count;
    for(auto& it: cnt)
        count.push_back(it.second);
    
    sort(count.begin(), count.end(), greater<int>());
    
    int total = 0;
    for(int i = 0; i < count.size(); ++i)
    {
        if(total + count[i] >= k)
            return i + 1;
        
        total += count[i];
    }
}
