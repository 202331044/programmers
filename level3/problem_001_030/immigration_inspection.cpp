#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

long long solution(int n, vector<int> times) {
//     sort(times.begin(), times.end());

//     ll left = 0;
//     ll right = 10000000000000;
//     ll answer = right;
    
//     while(left <= right)
//     {
//         ll mid = (left + right) / 2;
//         ll cnt = 0;
        
//         for(ll time: times)
//         {
//             if(mid >= time)
//                 cnt += mid / time;
//             else break;
//         }
        
//         if(cnt >= n)
//         {
//             answer = min(answer, mid);
//             right = mid - 1;
//         }
//         else
//             left = mid + 1;
//     }
    
//     return answer;
    
    sort(times.begin(), times.end());
    
    ll left = 1;
    ll right = (ll)n * times[0];
    ll answer = right;
    
    while(left <= right)
    {
        ll cnt = 0;
        ll mid = left + (right - left) / 2;
        
        for(ll time: times)
        {
            if(mid <= time) break;
            
            cnt += mid / time;
            
            if(cnt >= n) break;
        }
        
        if(cnt >= n)
        {
            right = mid - 1;
            answer = min(answer, mid);
        }
        else
            left = mid + 1;
    }
    
    return answer;
}
