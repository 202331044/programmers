#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    const int INF = 1e9;
    vector<int> answer;
    
    for(const auto& ball: balls)
    {
        int x = ball[0];
        int y = ball[1];
        
        int dist1 = (startX + x) * (startX + x)  + (startY - y) * (startY - y);
        int dist2 = (startX - x) * (startX - x)  + (startY + y) * (startY + y);
        int dist3 = (startX - (2 * m - x)) * (startX - (2 * m - x)) + 
                    (startY - y) * (startY - y);
        int dist4 = (startX - x) * (startX - x) + 
                    (startY - (2 * n - y)) * (startY - (2 * n - y));
        
        if(y == startY && x < startX) dist1 = INF;
        if(x == startX && y < startY) dist2 = INF;
        if(y == startY && x > startX) dist3 = INF;  
        if(x == startX && y > startY) dist4 = INF;
                 
        answer.push_back(min({dist1, dist2, dist3, dist4}));
    }
    
    return answer;
}
