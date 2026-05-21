#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
//     int cnt = 1, sum = 1;
    
//     for(int i = 1; i < section.size(); ++i)
//     {
//         int cur = sum + section[i] - section[i - 1];
        
//         if(cur > m)
//         {
//             sum = 1;
//             cnt++;
//         }
//         else sum += section[i] - section[i - 1];
//     }
    
//     return cnt;
    
    int cnt = 0;
    int painted = 0;
    for(int& s: section)
    {
        if(s > painted)
        {
            cnt++;
            painted = s + m - 1;
        }
    }
    return cnt;
}
