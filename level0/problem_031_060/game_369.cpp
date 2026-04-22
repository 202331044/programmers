#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    
    while(order > 0)
    {
        int rem = order % 10;
        if(rem == 3 || rem == 6 || rem == 9) answer++;
        order /= 10;
    }
    
    return answer;
}
