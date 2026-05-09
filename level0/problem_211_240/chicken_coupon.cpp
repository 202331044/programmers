#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
//     int service = 0;
//     int coupon = chicken;
//     int rem = 0;
    
//     while(coupon > 0)
//     {
//         service += coupon / 10;
//         rem += coupon % 10;
//         coupon = coupon / 10;

//         if(rem >= 10) 
//         {
//             coupon += rem / 10;
//             service += rem / 10;
//             rem %= 10;
//         }
//     }
    
//     return service;
    
    int answer = 0;
    while(chicken >= 10)
    {
        int service = chicken / 10;
        answer += service;
        chicken = chicken % 10 + service;
    }
    
    return answer;
}
