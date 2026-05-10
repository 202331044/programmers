#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int cnt = 0;
    
    for(int i = 1; ; ++i)
    {
        if(i % 3 == 0) continue;
        
        bool valid = true;
        int tmp = i;
        
        while(tmp > 0)
        {
            if(tmp % 10 == 3)
            {
                valid = false; 
                break;
            }
            tmp /= 10;
        }
            
        if(valid) cnt++;
        
        if(cnt == n) return i;
    }
}
