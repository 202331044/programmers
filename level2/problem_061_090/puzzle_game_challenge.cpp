#include <string>
#include <vector>

using namespace std;

bool isValid(const int mid, const long long limit,
             const vector<int>& times, const vector<int>& diffs)
{
    int n = times.size();
    int time_pre = 0;
    long long total_time = 0;

    for(int i = 0; i < n; ++i)
    {
        int time_cur = times[i];
        int diff = diffs[i];

        if(mid >= diff) total_time += time_cur;
        else total_time += (diff - mid) * (time_cur + time_pre) + time_cur;

        if(total_time > limit)
            return false;

        time_pre = time_cur;
    }
    
    return true;   
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
//     int maxLv = 100001, minLv = 1;
//     int level = 100000;
    
//     while(minLv < maxLv)
//     {
//         bool isValid = true;
//         int time_prev = 0;
//         long long total_time = 0;
//         int curLv = (maxLv + minLv) / 2;
        
//         for(int i = 0; i < times.size(); ++i)
//         {
//             int time_cur = times[i];
//             int diff = diffs[i];
            
//             if(curLv >= diff) 
//                 total_time += time_cur;
//             else
//                 total_time += (diff - curLv) * (time_cur + time_prev) + time_cur;
            
//             time_prev = time_cur;
            
//             if(total_time > limit)
//             {
//                 isValid = false;
//                 break;
//             }
//         }
        
//         if(isValid)
//         {
//             level = min(level, curLv);
//             if(maxLv == curLv) return level;
            
//             maxLv = curLv;
//         }
//         else
//         {
//             if(minLv == curLv) return level;
            
//             minLv = curLv;
//         }
//     }
        
//     return level;
    
    int n = times.size();
    int left = 1, right = 100000;
    
    while(left < right)
    {
        int mid = (right + left) / 2;
        
        if(isValid(mid, limit, times, diffs))
            right = mid;
        else
            left = mid + 1;
    }
    
    return left;
}
