#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// void dfs(int dist, int split, int leaf, int last, int& answer,
//          const int dist_limit, const int split_limit)
// {
//     if(answer < leaf) answer = leaf;
    
//     for(int i = last; i >= 0; --i)
//     {
//         if(dist + i <= dist_limit && split * 2 <= split_limit)
//             dfs(dist + i, split * 2, leaf - i + i * 2, i * 2,
//                 answer, dist_limit, split_limit);
        
//         if(dist + i <= dist_limit && split * 3 <= split_limit)
//             dfs(dist + i, split * 3, leaf - i + i * 3, i * 3, 
//                 answer, dist_limit, split_limit); 
//     }
// }

int solution(int dist_limit, int split_limit) {
    if(dist_limit == 0 || split_limit == 1) return 1;

//     int answer = 0;
//     int dist = 0;
//     int split = 1;
//     int leaf = 1;
//     int last = 1;

//     dfs(dist, split, leaf, last, answer, dist_limit, split_limit);
    
    long long answer = 0;
    
    for(int i = 0; i < 30; ++i)
    {
        for(int j = 0; j < 30; ++j)
        {
            long long curNodes = 1;
            long long dist = 0;
            long long split = 1;
            
            for(int layer = 0; layer < i + j; ++layer)
            {
                int k = (layer < i) ? 2 : 3;
                
                if(split * k > split_limit) break;
                
                if(dist + curNodes <= dist_limit)
                {
                    dist += curNodes;
                    curNodes *= k;
                    split *= k;
                    answer = max(answer, curNodes);
                }
                else
                {
                    answer = max(answer, (dist_limit - dist) * k + 
                                         (curNodes - (dist_limit - dist)));
                    break;
                }
            }
        }
    }
    
    return answer;
}
