#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

void find_part(const ll l, const ll r, ll s, ll e, int& answer)
{
    if(s == e) 
    {
        answer++;
        return;
    }
    
    ll len = (e - s + 1) / 5;
    
    ll ns = max(s, l);
    ll ne = min(s + len - 1, r);
    if(s <= ns && e >= ne && ns <= ne)
        find_part(ns, ne, s, s + len - 1, answer);
    
    ns = max(s + len, l);
    ne = min(s + len * 2 - 1, r);
    if(s <= ns && e >= ne && ns <= ne)
        find_part(ns, ne, s + len, s + len * 2 - 1, answer);
    
    
    ns = max(s + len * 3, l);
    ne = min(s + len * 4 - 1, r);
    if(s <= ns && e >= ne && ns <= ne)
        find_part(ns, ne, s + len * 3, s + len * 4 - 1, answer);
    
    ns = max(s + len * 4, l);
    ne = min(s + len * 5 - 1, r);
    if(s <= ns && e >= ne && ns <= ne)
        find_part(ns, ne, s + len * 4, s + len * 5 - 1, answer);
    
    return;
}

int calcOnes(int n, ll x, const vector<ll>& blockCnt, const vector<int>& cntOnes)
{
    if(x <= 0) return 0;
    if(n == 0) return 1;
    
    ll blockSize = blockCnt[n - 1];
    
    ll size = x / blockSize;
    ll rem = x % blockSize;
    
    int answer = 0;
    for(int i = 0; i < size; ++i)
    {
        if(i == 2) continue;
        answer += cntOnes[n - 1];
    }
    
    if(size != 2)
        answer += calcOnes(n - 1, rem, blockCnt, cntOnes);
    
    return answer;
}

int solution(int n, long long l, long long r) {
//     int answer = 0;
    
//     ll s = 1;
//     ll e = pow(5, n);
    
//     find_part(l, r, 1, e, answer);
    
    vector<ll> blockCnt(21, 0);
    blockCnt[0] = 1;
    
    vector<int> cntOnes(21, 0);
    cntOnes[0] = 1;
    
    for(int i = 1; i <= n; ++i)
    {
        blockCnt[i] = blockCnt[i - 1] * 5;
        cntOnes[i] = cntOnes[i - 1] * 4;
    }
    
    return calcOnes(n, r, blockCnt, cntOnes) - calcOnes(n, l - 1, blockCnt, cntOnes);
}
