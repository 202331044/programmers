#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int width = wallet[0], height = wallet[1];
    
    if(width > height) 
        swap(width, height);
    
    int minLen= bill[0], maxLen = bill[1];
    int cnt = 0;
    
    while(true)
    {
        if(minLen > maxLen) 
            swap(minLen, maxLen);
        
        if(minLen <= width && maxLen <= height) 
            return cnt;
        
        maxLen /= 2;
        cnt++;
    }

    return cnt;
}
