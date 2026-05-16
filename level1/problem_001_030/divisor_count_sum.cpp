#include <string>
#include <vector>
#include <cmath>

using namespace std;

int divisor(int num)
{
    int cnt = 0;
    
    for(int i = 1; i * i <= num; ++i)
    {
        if(num % i == 0)
        {
            if(num / i == i) cnt++;
            else cnt += 2;
        }
    }
    
    return cnt;
}

int solution(int left, int right) {
     int sum = 0;
    
//     for(int i = left; i <= right; ++i)
//     {
//         if(divisor(i) % 2 == 0) sum += i;
//         else sum -= i;
//     }
       
//     return sum;
    
    for(int i = left; i <= right; ++i)
    {
        if(static_cast<int>(sqrt(i)) * static_cast<int>(sqrt(i)) == i)
            sum -= i;
        else
            sum += i;
    }
    
    return sum;
}
