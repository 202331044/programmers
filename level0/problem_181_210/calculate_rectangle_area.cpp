#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> dots) {
    int x1, x2, y1, y2;
    
    x1 = dots[0][0];
    x2 = x1 != dots[1][0] ? dots[1][0] : dots[2][0];
    
    y1 = dots[0][1];
    y2 = y1 != dots[1][1] ? dots[1][1] : dots[2][1];
    
    return abs(x1 - x2) * abs(y1 - y2);
}
