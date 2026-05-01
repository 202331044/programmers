#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int solution(vector<int> array, int n) {
    int diff = 100, minVal = 100;
    
    for(int num: array)
    {
        if(abs(num - n) < diff)
        {
            diff = abs(num - n);
            minVal = num;
        }
        else if(abs(num - n) == diff)
            minVal = num < minVal ? num : minVal;
    }
    
    return minVal;
}
