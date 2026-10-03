#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
//     int answer = 0;
//     int idx = 0;
//     int cur = w + 1;
    
//     while(cur <= n + w)
//     {
//         if(idx < stations.size() && stations[idx] <= cur)
//         {
//             cur = stations[idx] + 2 * w + 1;
//             idx++;
//         }
//         else
//         {
//             cur += 2 * w + 1;
//             answer++;
//         }
//     }

//     return answer;
    
    int answer = 0;
    int cur = 1;
    int coverage = 2 * w + 1;
    
    for(int station: stations)
    {
        int left = station - w;
        
        if(cur < left)
        {
            int len = (left - cur);
            answer += (len + coverage - 1) / coverage;
        }
        
        cur = station + w + 1;
    }
    
    if(cur <= n)
    {
        int len = n - cur + 1;
        answer += (len + coverage - 1) / coverage;
    }
    
    return answer;
}
