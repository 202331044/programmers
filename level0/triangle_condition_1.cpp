#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int a = sides[0], b = sides[1], c = sides[2];
    int total = a + b + c;
    int maxSide = max({a, b, c});
    
    if(maxSide < (total - maxSide)) return 1;
    return 2;
}
