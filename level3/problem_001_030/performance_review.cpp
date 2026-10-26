#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
//     vector<int> wanho = scores[0];
//     sort(scores.begin(), scores.end(), greater<vector<int>>());

//     vector<vector<int>> remain;
//     int premaxB = 0;
//     int curA = scores[0][0];
//     int maxB = scores[0][1];
//     bool isValid = false;
    
//     for(auto score: scores)
//     {
//         int a = score[0];
//         int b = score[1];
        
//         if(b >= maxB ||
//           (a == curA && b >= premaxB))
//         {
//             remain.push_back({a, b});
//             if(a == wanho[0] && b == wanho[1])
//                 isValid = true;
//         } 
        
//         if(a != curA)
//             premaxB = maxB;
        
//         curA = a;
//         maxB = max(maxB, b);
//     }
    
//     if(!isValid) return -1;
    
//     vector<int> answer;
//     for(auto ab: remain)
//         answer.push_back(ab[0] + ab[1]);

//     sort(answer.begin(), answer.end(), greater<int>());
    
//     int sum = wanho[0] + wanho[1];
//     for(int i = 0; i < answer.size(); ++i)
//         if(answer[i] == sum) return i + 1;
    
    vector<int> wanho = scores[0];
    
    sort(scores.begin(), scores.end(), [](const auto& a, const auto& b)
         {
             if(a[0] != b[0]) return a[0] > b[0];
             return a[1] < b[1];
         });
    
    int maxB = 0;
    bool isValid = false;
    vector<int> sum;
    
    for(const auto& score: scores)
    {
        int a = score[0];
        int b = score[1];
        
        if(b < maxB) continue;
        
        sum.push_back(a + b);
        maxB = b;
        
        if(a == wanho[0] && b == wanho[1])
            isValid = true;
    }
    
    if(!isValid) return -1;
    
    sort(sum.begin(), sum.end(), greater<int>());
    
    for(int i = 0; i < sum.size(); ++i)
        if(sum[i] == wanho[0] + wanho[1])
            return i + 1;
}
