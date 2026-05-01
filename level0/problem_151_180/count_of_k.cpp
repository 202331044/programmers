#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int cnt = 0;
    
    for(int l = i; l <= j; ++l)
    {
        int tmp = l;
        while(tmp != 0)
        {
            if(tmp % 10 == k) cnt++;
            tmp /= 10;
        }
    }
    
    return cnt;
}
