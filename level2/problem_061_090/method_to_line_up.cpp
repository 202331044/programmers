#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> factorial(int num)
{
    vector<long long> arr;
    long long answer = 1;
    
    for(int i = 1; i < num; ++i)
    {
        answer *= i;
        arr.push_back(answer);
    }
    
    reverse(arr.begin(), arr.end());
    return arr;
}

vector<int> solution(int n, long long k) {
//     vector<long long> vec = factorial(n);
//     vector<int> index;
    
//     for(long long num: vec)
//     {
//         for(int i = 1; i <= n; ++i)
//         {
//             if(num * i >= k)
//             {
//                 index.push_back(i);
//                 k -= num * (i - 1);
//                 break;
//             }
//         }
//     }
    
//     vector<int> numbers(n);
//     for(int i = 1; i <= n; ++i)
//         numbers[i - 1] = i;
    
//     vector<int> answer;
//     for(int idx: index)
//     {
//         answer.push_back(numbers[idx - 1]);
//         numbers.erase(numbers.begin() + (idx - 1));
//     }
    
//     answer.push_back(numbers[0]);
//     return answer;
    
    k--;
    
    vector<int> numbers;
    long long fact = 1;
    
    for(int i = 1; i <= n; ++i)
    {
        numbers.push_back(i);
        fact *= i;
    }
    
    vector<int> answer;
    for(int i = n; i > 0; --i)
    {
        fact /= i;
        int idx = k / fact;
        
        answer.push_back(numbers[idx]);
        numbers.erase(numbers.begin() + idx);
        
        k %= fact;
    }
    
    return answer;
}
