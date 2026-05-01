#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int num = 1, i = 1;
    
    while(num <= n)
    {
        if(num * i > n) return i-1;
        num *= i;
        i++;
    }
}
