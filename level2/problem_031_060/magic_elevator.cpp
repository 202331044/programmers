#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
//     string str = to_string(storey);
//     bool up = false;
//     int answer = 0;
    
//     while(!str.empty())
//     {
//         int num = (str.back() - '0');
//         str.pop_back();
        
//         if(up)
//         {
//             num++;
//             up = (num >= 10) ? true : false;
//             num %= 10;
//         }
        
//         if(num == 5)
//         {
//             if(!str.empty() && str.back() >= '5') up = true; 
//             answer += 5;
//         }
//         else if(num < 5)
//             answer += num;
//         else
//         {
//             answer += (10 - num);
//             up = true;
//         }
//     }
    
//     if(up) answer++;
    
//     return answer;
    
    int answer = 0;
    
    while(storey > 0)
    {
        int cur = storey % 10;
        int next = storey / 10 % 10;
        
        if(cur == 5)
        {
            if(next >= 5) storey += 10;
            answer += 5;
        }
        else if(cur < 5)
            answer += cur;  
        else
        {
            answer += 10 - cur;
            storey += 10;
        }
        
        storey /= 10;
    }
    
    return answer;
}
