#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer;
    
    while(n > 0)
    {
        int rem = n % 3;
        
        if(rem == 0)
        {
            answer += '4';
            n = n / 3 - 1;
        }
        else
        {
            answer += ('0' + rem);
            n /= 3;
        }
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
