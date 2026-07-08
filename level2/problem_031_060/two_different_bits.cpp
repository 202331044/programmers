#include <string>
#include <vector>

using namespace std;

// string to_str(long long number)
// {
//     string str;
//     while(number)
//     {
//         str += number % 2 == 0 ? '0' : '1';
//         number /= 2;
//     }
    
//     return str;
// }

// long long to_number(string& str)
// {
//     long long ans = 0;
//     long long term = 1;
//     for(char ch: str)
//     {
//         ans += (ch -'0') * term;
//         term *= 2;
//     }
    
//     return ans;
// }

vector<long long> solution(vector<long long> numbers) {
    
//     vector<long long> answer;
//     for(long long number: numbers)
//     {
//         bool isChanged = false;
//         string str = to_str(number);
        
//         for(int i = 0; i < str.size(); ++i)
//         {
//             if(str[i] == '0')
//             {
//                 str[i] = '1';
//                 if(i - 1 >= 0) str[i - 1] = '0';
//                 isChanged = true;
//                 break;
//             }
//         }
        
//         if(!isChanged)
//         {
//             str += '1';
//             if(str.size() - 1 > 0) str[str.size() - 2] = '0';
//         }
        
//         answer.push_back(to_number(str));
//     }
    
//     return answer;
    
    vector<long long> answer;
    for(long long number: numbers)
    {
        if(number % 2 == 0) 
            answer.push_back(number + 1);
        else
        {
            long long k = number ^ (number + 1);
            answer.push_back(number + (k >> 2) + 1);
        }
            
    }
    
    return answer;
}
