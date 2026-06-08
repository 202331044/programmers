#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int f0 = 0, f1 = 1;
    
    for(int i = 2; i <= n; ++i)
    {
        int f2 = (f0 + f1) % 1234567;
        f0 = f1;
        f1 = f2;
    }
    
    return f1;
}
