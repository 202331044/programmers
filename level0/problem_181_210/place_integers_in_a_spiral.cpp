#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    int num = n * n;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    int r = 0, c = 0;
    int dir = 0;
    
//     int cnt = 1, num = n * n;
//     int r = 0, c = 0;
//     int a = 0, b = 1;
    
//     while(cnt <= num)
//     {
//         if(r < n && r >= 0 && c < n && c >= 0 && answer[r][c] == 0)
//         {
//             answer[r][c] = cnt++;
//             r += a;
//             c += b;
//         } 
//         else
//         {
//             r -= a;
//             c -= b;
            
//             if(a == 0 && b == 1) a = 1, b = 0;
//             else if(a == 1 && b == 0) a = 0, b = -1;
//             else if(a == 0 && b == -1) a = -1, b = 0;
//             else if(a == -1 && b == 0) a = 0, b = 1;
            
//             r += a;
//             c += b;
//         }  
//     }
    
    for(int i = 1; i <= num; ++i)
    {
        answer[r][c] = i;
        
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        
        if(nr >= n || nr < 0 || nc >= n || nc < 0 || answer[nr][nc] != 0)
        {
            dir = (dir + 1) % 4;
            nr = r + dr[dir];
            nc = c + dc[dir];
        }
        r = nr;
        c = nc;               
    }
    
    return answer;
}
