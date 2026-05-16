#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {    
    if(num == 1) return 0;
    
    int cnt = 0;
    long long tmp = num;
    
    while(tmp != 1 && cnt < 500)
    {
        if(tmp % 2 == 0) tmp /= 2;
        else tmp = tmp * 3 + 1;
        cnt++;
    }
    
    if(tmp != 1) return -1;
    return cnt;
}
