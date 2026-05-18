#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxW = 0, maxH = 0;
    
    for(auto size: sizes)
    {
        int width = size[0], height = size[1];
        if(width > height) swap(width, height);
        
        if(maxW < width) maxW = width;
        if(maxH < height) maxH = height;
    }
    
    return maxW * maxH;
}
