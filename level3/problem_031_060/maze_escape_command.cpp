#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, -1, 1, 0};
char str[4] = {'d', 'l', 'r', 'u'};

void dfs(
    string& answer, 
    string route, 
    int x, int y, 
    const int r, const int c, const int k, 
    const int n, const int m
)
{
    if(answer.size() == k) return;

    if(x == r && y == c && route.size() == k)
    {
        answer = route;
        return;
    }

    if(abs(x - r) + abs(y - c) > k - route.size()) return;
    
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dr[i];
        int ny = y + dc[i];

        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m)
            dfs(answer, route + str[i], nx, ny, r, c, k, n, m);  
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
//     string answer, route;
//     int dist = abs(x - r) + abs(y - c);
    
//     if(dist > k) return "impossible";
//     if((k - dist) % 2 != 0) return "impossible";
    
//     dfs(answer, route, x, y, r, c, k, n, m);
    
//     return answer;
    
    string answer;
    int dist = abs(x - r) + abs(y - c);
    
    if(dist > k || (k - dist) % 2 != 0) return "impossible";
    
    for(int i = 1; i <= k; ++i)
    {
        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dr[dir];
            int ny = y + dc[dir];
            
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            
            int remain = k - i;
            int dist = abs(nx - r) + abs(ny - c);
            
            if(dist <= remain && (remain - dist) % 2 == 0)
            {
                answer += str[dir];
                x = nx;
                y = ny;
                break;
            }
        }
    }
    
    return answer;
}
