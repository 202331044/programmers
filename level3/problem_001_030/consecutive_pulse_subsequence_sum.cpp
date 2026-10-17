#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
//     long long answer1 = 0, answer2 = 0;
//     long long cum = 0;

//     for(int right = 0; right < sequence.size(); ++right)
//     {
//         if(right % 2 == 0) cum += sequence[right];
//         else cum -= sequence[right];
        
//         if(cum < 0)
//             cum = 0;

//         answer1 = max(answer1, cum);
//     }
    
//     cum = 0;
//     for(int right = 0; right < sequence.size(); ++right)
//     {
//         if(right % 2 == 0) cum -= sequence[right];
//         else cum += sequence[right];
        
//         if(cum < 0)
//             cum = 0;

//         answer2 = max(answer2, cum);
//     }
    
//     return max(answer1, answer2);
    
    long long answer = 0;
    long long sum1 = 0, sum2 = 0;
    
    for(int i = 0; i < sequence.size(); ++i)
    {
        long long num = sequence[i];
        
        if(i % 2 == 0)
        {
            sum1 = max(0LL, sum1 + num);
            sum2 = max(0LL, sum2 - num);
        }
        else
        {
            sum1 = max(0LL, sum1 - num);
            sum2 = max(0LL, sum2 + num);
        }
        
        answer = max({answer, sum1, sum2});
    }
    
    return answer;
}
