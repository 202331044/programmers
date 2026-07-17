#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
//     map<int, int> count;
//     map<int, vector<int>> ranges;
    
//     for(int w: weights)
//         count[w]++;
    
//     for(auto& [w, cnt]: count)
//         ranges[w].insert(ranges[w].end(), {w * 2, w * 3, w * 4});

//     long long answer = 0;
//     for(auto& [w1, cnt1]: count)
//     {
//         answer += 1ll * cnt1 * (cnt1 - 1) / 2;
        
//         for(auto& [w2, cnt2]: count)
//         {
//             if(w1 >= w2) continue;
//             bool isStop = false;
            
//             for(int cmp1: ranges[w1])
//             {
//                 for(int cmp2: ranges[w2])
//                 {
//                     if(cmp1 == cmp2) 
//                     {
//                         answer += 1ll * cnt1 * cnt2;
//                         isStop = true;
//                         break;
//                     }
//                 }
                
//                 if(isStop) break;
//             }
//         }
//     }
    
//     return answer;
    
    map<int, int> count;
    
    for(int w: weights)
        count[w]++;
    
    long long answer = 0;
    for(auto& [w, cnt]: count)
    {
        answer += 1ll * cnt * (cnt - 1) / 2;
        
        if(w % 2 == 0 && count.count(w / 2))
            answer += 1ll * count[w] * count[w / 2];
        if(w % 3 == 0 && count.count(w / 3 * 2))
            answer += 1ll * count[w] * count[w / 3 * 2];
        if(w % 4 == 0 && count.count(w / 4 * 3))
            answer += 1ll * count[w] * count[w / 4 * 3];
    }
    
    return answer;
}
