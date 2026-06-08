#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int cnt = 0;
    int sum = 0, start = 1;
    
    for(int i = 1; i <= n; ++i)
    {
        sum += i;
        
        while(sum > n)
        {
            sum -= start;
            start++;
        }
        
        if(sum == n)
            cnt++;
    }
    
    return cnt;
}
