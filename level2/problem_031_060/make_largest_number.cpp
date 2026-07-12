#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
//     string answer;
//     int size = number.size() - k;
    
//     for(char ch: number)
//     {
//         if(k == 0 || (!answer.empty() && answer.back() >= ch)) 
//             answer.push_back(ch);
//         else
//         {
//             while(k != 0 && !answer.empty() && answer.back() < ch)
//             {
//                 answer.pop_back();
//                 k--;
//             }
            
//             answer.push_back(ch);
//         }
//     }
    
//     return answer.substr(0, size);
    
    string answer;
    
    for(char ch: number)
    {
        while(k > 0 && !answer.empty() && answer.back() < ch)
        {
            answer.pop_back();
            k--;
        }
        answer.push_back(ch);
    }
    
    return answer.substr(0, number.size() - k);
}
