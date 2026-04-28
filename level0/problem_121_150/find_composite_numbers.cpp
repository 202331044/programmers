#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> isFactor(n + 1, 1);
    
    for(int i = 2; i*i <= n; ++i)
    {
        if(isFactor[i] == 0) continue;
        
        for(int j = i * i; j <= n; j += i)
            isFactor[j] = 0;  
    }
    
    int cnt = 0;
    
    for(int k = 0; k <= n; ++k)
        if(isFactor[k] == 0) cnt++;
    
    return cnt;
}
