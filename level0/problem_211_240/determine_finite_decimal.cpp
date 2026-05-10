#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(int a, int b) {
//     int mod = 2;
    
//     while(mod <= a && mod <= b)
//     {
//         while(a % mod == 0 && b % mod == 0)
//         {
//             a /= mod;
//             b /= mod;
//         }
//         mod++;
//     }

    int mod = gcd(a, b);
    b /= mod;
    
    while(b % 2 == 0) b /= 2;
    while(b % 5 == 0) b /= 5;
    
    if(b == 1) return 1;
    return 2;
}
