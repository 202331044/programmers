#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
//     int cnt = 1;
    
//     while(a > 0 || b > 0)
//     {
//         if(a & 1) a++;
//         if(b & 1) b++;
        
//         if(a == b) return cnt;
        
//         a >>= 1;
//         b >>= 1;
//         cnt++;
//     }
    
    int round = 0;
    
    while(a != b)
    {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        
        round++;
    }
    
    return round;
}
