#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    const int MAX = 1000000007;
    
    int a = 1, b = 1;
    if(n == 1) return 1;
    
    for(int i = 2; i <= n; ++i)
    {
        int c = (a + b) % MAX;
        a = b;
        b = c;
    }
    
    return b;
}
