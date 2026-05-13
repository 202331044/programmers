#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool parallel(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d)
{
    int x1 = a[0] - b[0], y1 = a[1] - b[1];
    int x2 = c[0] - d[0], y2 = c[1] - d[1];
    
    return x1 * y2 == x2 * y1;
}
int solution(vector<vector<int>> dots) {

//     double x1 = dots[0][0], y1 = dots[0][1];
//     double x2 = dots[1][0], y2 = dots[1][1];
//     double x3 = dots[2][0], y3 = dots[2][1];
//     double x4 = dots[3][0], y4 = dots[3][1];
    
//     double a = (x1 - x2) / (y1 - y2);
//     double b = (x3 - x4) / (y3 - y4);
    
//     double c = (x1 - x3) / (y1 - y3);
//     double d = (x2 - x4) / (y2 - y4);
    
//     double e = (x1 - x4) / (y1 - y4);
//     double f = (x2 - x3) / (y2 - y3);
    
//     if(a == b || c == d || e == f) return 1;
//     return 0;
    
//     int x1 = dots[0][0], y1 = dots[0][1];
//     int x2 = dots[1][0], y2 = dots[1][1];
//     int x3 = dots[2][0], y3 = dots[2][1];
//     int x4 = dots[3][0], y4 = dots[3][1];
    
//     if((y2 - y1) * (x4 - x3) == (y4 - y3)* (x2 - x1) ||
//       (y3 - y1) * (x4 - x2) == (y4 - y2) * (x3 - x1) ||
//       (y4 - y1) * (x3 - x2) == (y3 - y2) * (x4 - x1)) return 1;
    
//     return 0;
    
    if(parallel(dots[0], dots[1], dots[2], dots[3]) ||
       parallel(dots[0], dots[2], dots[1], dots[3]) ||
       parallel(dots[0], dots[3], dots[1], dots[2])) return 1;
    
    return 0;
}
