#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 1; i*i <= n; ++i)
    {
        if(n % i == 0)
        {
            if(i * i != n) answer += 2;
            else answer++;
        }
    }
         
    return answer;
}
