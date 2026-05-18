#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    string str;
    
    while(n)
    {
        str += (n % 3 + '0');
        n /= 3;
    }
    
    reverse(str.begin(), str.end());
    
    int tmp = 1;
    for(int i = 0; i < str.size(); ++i)
    {
        answer += (str[i] - '0') * tmp;
        tmp *= 3;
    }
    
    return answer;
}
