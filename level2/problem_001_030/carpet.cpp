#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    for(int h = 1; h * h <= yellow; ++h)
    {
        if(yellow % h != 0) continue;
        
        int w = yellow / h;
        
        if(2 * h + 2 * w + 4 == brown) 
            return {w + 2, h + 2};
    }
}
