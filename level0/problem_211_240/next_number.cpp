#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int a = common[0], b = common[1], c = common[2];
    
    if(c - b == b - a) 
        return common.back() + (c - b);
    else 
        return common.back() * (c / b);
}
