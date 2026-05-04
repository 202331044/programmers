#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    long long answer = 1;
    
    if(share > balls - share) share = balls - share;
    
    for(int i = 1; i <= share; ++i)
        answer = answer * (balls - share + i) / i;
    
    return answer;
}
