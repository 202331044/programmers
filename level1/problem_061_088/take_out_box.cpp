#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
//     int rows = n / w;
//     if(n % w > 0) rows++;
    
//     vector<vector<int>> vec(rows, vector<int>(w, 0));
    
//     int r = rows - 1, c = 0;
//     int dc = 1; 
//     int cnt = 1;

//     while(r >= 0 && cnt <= n)
//     {
//         while(c >= 0 && c < w)
//         {
//             vec[r][c] = cnt++;
            
//             if(cnt > n) break;
//             c += dc;
//         }
//         dc = -dc;
//         c += dc;
//         r--;
//     }
    
//     for(int i = 0; i < rows; ++i)
//     {
//         for(int j = 0; j < w; ++j)
//         {
//             if(vec[i][j] == num)
//             {
//                 int answer = 0;
//                 while(i >= 0 && vec[i][j] != 0)
//                 {
//                     answer++;
//                     i--;
//                 }
//                 return answer;
//             }
//         }
//     }
    
    int r = (num - 1) / w;
    int c = (num - 1) % w;
    
    if(r % 2 != 0) c = w - c - 1;
    
    int answer = 1;
    
    for(int i = r + 1; ; ++i)
    {
        int box = i * w + c + 1;
        if(i % 2 != 0) box = i * w + (w - c);
        
        if(box <= n)
            answer++;
        else
            return answer;
    }
}
