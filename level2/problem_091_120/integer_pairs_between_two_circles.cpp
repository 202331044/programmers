#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

ll solution(int r1, int r2) {
//     ll answer = 0;
//     ll duplication = 0;
    
//     for(ll x1 = 0; x1 <= r1; ++x1)
//     {
//         ll y1 = ceil(sqrt(static_cast<ll>(r1) * r1 - x1 * x1));
//         ll y2 = sqrt(static_cast<ll>(r2) * r2 - x1 * x1);

//         answer += (y2 - y1 + 1);
//         if(x1 == 0) duplication = (y2 - y1 + 1);
//     }
    
//     for(ll x2 = r1 + 1; x2 <= r2; ++x2)
//     {
//         ll y = sqrt(static_cast<ll>(r2) * r2 - x2 * x2);
//         answer += y + 1;
//     }

//     answer *= 4;
//     answer -= (duplication * 4);

//     return answer;
    
    ll answer = 0;
    
    for(ll x = 0; x <= r2; ++x)
    {
        ll y2 = sqrt(1LL * r2 * r2 - x * x);
        ll y1 = 0;
        
        if(x <= r1)
            y1 = ceil(sqrt(1LL * r1 * r1 - x * x));
        
        answer += (y2 - y1 + 1);
    }
    
    answer *= 4;
    answer -= (r2 - r1 + 1) * 4;
    
    return answer;
}
