#include <string>
#include <vector>

using namespace std;

int getOneCnt(int num)
{
    int cnt = 0;
    
    while(num > 0)
    {
        // if(num % 2 == 1) cnt++;
        // num /= 2;
        num &= (num - 1);
        cnt++;
    }
    
    return cnt;
}

int solution(int n) {
    int one = getOneCnt(n);
    
    for(int i = n + 1; ; ++i)
    {
        if(one == getOneCnt(i)) 
            return i;
    }
}
