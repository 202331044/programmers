#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
//     int month = 1, day = 1;
//     int cnt = 0;
    
//     while(month != a || day != b)
//     {
//         cnt++;
//         day++;
        
//         if(month == 2 && day > 29) 
//         {
//             month++;
//             day %= 29;
//         }  
//         else if((month == 4 || month == 6 || month == 9 || month == 11) && day >30)
//         {
//             month++;
//             day %= 30;
//         }
//         else if(day > 31) 
//         {
//             month++;
//             day %= 31;
//         }
//     }

//     vector<string> days = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
//     return days[cnt % 7];
    
    vector<int> month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> days = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
    int cnt = b - 1;
    for(int i = 0; i < a - 1; ++i)
        cnt += month[i];
    
    return days[cnt % 7];
}
