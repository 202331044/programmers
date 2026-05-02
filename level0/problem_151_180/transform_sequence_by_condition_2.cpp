#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    //vector<int> cmp = arr;
    int x = 0;
    
    
    while(true)
    {
        bool changed = false;
        for(int& n: arr)
        {
            int pre = n;
            if(n >= 50 && n % 2 == 0) n /= 2;
            else if(n < 50 && n % 2 != 0) n = n * 2 + 1;
            
            if(pre != n) changed = true;
        }
        
        if(!changed) return x;
        //if(cmp == arr) return x;
        
        x++;
        //cmp = arr;
    }
}
