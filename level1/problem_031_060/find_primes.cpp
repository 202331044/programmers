#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int cnt = 0;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for(int i = 2; i * i <= n; ++i)
    {
        if(isPrime[i] == false) continue;
        
        for(int j = i * i; j <= n; j += i)
            isPrime[j] = false;
    }
    
    for(bool b: isPrime)
        if(b) cnt++;
    
    return cnt;
}
