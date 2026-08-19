#include <string>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

ll solution(int k, int d) {
    ll answer = 0;
    ll ld = d;
    
    for(ll x = 0; x <= d; x += k)
    {
        ll limy = sqrt(ld * ld - x * x);
        answer += (limy / k) + 1;
    }
    
    return answer;
}
