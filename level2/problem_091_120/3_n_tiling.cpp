#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    const int MOD =  1000000007;
    
    vector<long long> dp(n + 1, 0);
//     dp[0] = 1;
    
//     for(int i = 2; i <= n; i += 2)
//     {
//         dp[i] += (3 * dp[i - 2]) % MOD;
        
//         for(int j = 4; j <= i; j += 2)
//             dp[i] += (dp[i - j] * 2) % MOD;
        
//         dp[i] %= MOD;
//     }
    
    dp[0] = 1;
    dp[2] = 3;
    
    for(int i = 4; i <= n; i += 2)
        dp[i] = ((4 * dp[i - 2]) % MOD - dp[i - 4] + MOD) % MOD;
    
    return dp[n];
}
