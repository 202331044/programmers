#include <string>
#include <vector>

using namespace std;
const int MAX = 1234567;

long long solution(int n) {
    long long f0 = 0, f1 = 1;
    
    for(int i = 1; i <= n; ++i)
    {
        long long f2 = (f0 % MAX + f1 % MAX) % MAX;
        f0 = f1;
        f1 = f2;
    }
    
    return f1;
}
