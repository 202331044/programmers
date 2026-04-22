#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // if(n % 2 == 0)
    //     for(int i = 2; i <= n; i += 2) answer += i*i;
    // else
    //     for(int i = 1; i <= n; i += 2) answer += i;
    
    int k = (n/2);
    if (n % 2 == 0) answer = (k * (k + 1) * (2*k+1) / 6) * 4;
    else answer = ((n+1)/2) * ((n+1)/2);
    
    return answer;
}
