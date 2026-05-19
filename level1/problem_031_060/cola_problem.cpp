#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
//     int answer = 0;
//     int cola = n / a * b;
//     int rem = n % a;

//     while(cola > 0)
//     {
//         answer += cola;
//         rem += cola % a;
//         cola = cola / a * b;
   
//         if(rem >= a)
//         {
//             cola += rem / a * b;
//             rem %= a;
//         }
//     }
    
//     answer += rem / a * b;
//     return answer;
    
    int answer = 0;

    while(n >= a)
    {
        int cola = n / a * b;
        answer += cola;
        n = cola + n % a;
    }
    
    return answer;
}
