#include <string>
#include <set>
#include <algorithm>

using namespace std;

struct Edge
{
    int x1, y1;
    int x2, y2;
    
    bool operator<(const Edge& e) const
    {
        if(x1 != e.x1) return x1 < e.x1;
        if(y1 != e.y1) return y1 < e.y1;
        if(x2 != e.x2) return x2 < e.x2;
        return y2 < e.y2;
    }
};

int solution(string dirs) {
//     int arr[11][11][11][11] = {0,};
//     int x = 5, y = 5;
    
//     for(char ch: dirs)
//     {
//         switch(ch)
//         {
//             case 'U':
//                 if(y + 1 <= 10)
//                 {
//                     arr[x][y][x][y + 1]++;
//                     y++;
//                 }   
//                 break;
//             case 'D':
//                 if(y - 1 >= 0)
//                 {
//                     arr[x][y - 1][x][y]++;
//                     y--;
//                 }    
//                 break;
//             case 'R':
//                 if(x + 1 <= 10)
//                 {
//                     arr[x][y][x + 1][y]++;
//                     x++;
//                 }     
//                 break;
//             case 'L':
//                 if(x - 1 >= 0)
//                 {
//                     arr[x - 1][y][x][y]++;
//                     x--;
//                 }     
//                 break;
//         }
//     }
    
//     int answer = 0;
//     for(int i = 0; i <= 10; ++i)
//         for(int j = 0; j <= 10; ++j)
//             for(int k = 0; k <= 10; ++k)
//                 for(int l = 0; l <= 10; ++l)
//                     if(arr[i][j][k][l] > 0) 
//                         answer++;

//     return answer;
    
    set<Edge> routes;
    int x = 5, y = 5;
    
    for(char ch: dirs)
    {
        int nx = x, ny = y;
        switch(ch)
        {
            case 'U': ny++; break;
            case 'D': ny--; break;
            case 'R': nx++; break;
            case 'L': nx--; break;
        }
        
        if(nx >= 0 && nx <= 10 && ny >= 0 && ny <= 10)
        {
            routes.insert({min(x, nx), min(y, ny), max(x, nx), max(y, ny)});
            x = nx, y = ny;
        }   
    }
    
    return routes.size();
}
