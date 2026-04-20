#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // for(int i = 2; i <= n; ++i)
    //     if(i % 2 == 0)  answer += i;
    
    answer = (n/2)*(n/2+1);
    
    return answer;
}
