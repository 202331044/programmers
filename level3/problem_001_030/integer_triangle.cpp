#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    
//     vector<int> pre(n, 0);
//     pre[0] = triangle[0][0];
    
//     for(int i = 1; i < n; ++i)
//     {
//         vector<int> post(n, 0);
        
//         for(int j = 0; j < i; ++j)
//         {
//             post[j] = max(post[j], pre[j] + triangle[i][j]);
//             post[j + 1] = pre[j] + triangle[i][j + 1];       
//         }
//         pre = post;
//     }
    
//     int answer = 0;
    
//     for(int i = 0; i < n; ++i)
//         answer = max(answer, pre[i]);
    
//     return answer;
    
    for(int i = 1; i < n; ++i)
    {
        triangle[i][0] += triangle[i - 1][0];
        
        for(int j = 1; j < i; ++j)
            triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
        
        triangle[i][i] += triangle[i - 1][i - 1];
    }
    
    return *max_element(triangle[n - 1].begin(), triangle[n - 1].end());
}
