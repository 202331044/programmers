#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int cnt = 0;
    
    for(int num: array)
    {
        while(num != 0)
        {
            if(num % 10 == 7) cnt++;
            num /= 10;
        }
    }
    
    return cnt;
}
