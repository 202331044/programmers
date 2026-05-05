#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int a = sides[0], b = sides[1];
    if(a < b) swap(a, b);
    
    int minVal = a - b + 1;
    int maxVal = a + b - 1;
    
    return maxVal - minVal + 1;
}
