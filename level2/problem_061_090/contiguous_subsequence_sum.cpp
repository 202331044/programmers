#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
//     int minLen = 1000000;
//     int start = 0;
//     int sum = 0;
    
//     vector<int> answer(2, 0);
//     for(int end = 0; end < sequence.size(); ++end)
//     {
//         sum += sequence[end];
        
//         while(sum > k)
//             sum -= sequence[start++];
        
//         if(sum == k && start <= end && minLen > end - start)
//         {
//             answer[0] = start;
//             answer[1] = end;
//             minLen = end - start;
//         }
//     }
    
//     return answer;
    
    int minLen = 1000001;
    int left = 0;
    int sum = 0;
    
    vector<int> answer(2, 0);
    for(int right = 0; right < sequence.size(); ++right)
    {
        sum += sequence[right];
        
        while(sum > k)
            sum -= sequence[left++];
        
        if(sum == k)
        {
            int len = right - left + 1;
            
            if(minLen > len)
            {
                minLen = len;
                answer[0] = left;
                answer[1] = right;
            }
        }
    }
    
    return answer;
}
