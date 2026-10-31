#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    const int MOD =  1000000007;
    
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    
    for(int m: money)
    {
        for(int i = m; i <= n; ++i)
        {
            dp[i] += dp[i - m];
            dp[i] %= MOD;
        }
    }
    
    return dp[n];
}
