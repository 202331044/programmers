#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int n, int m) {
//     int a = gcd(n, m);
//     int b = a * (n/a) * (m/a);
    
//     return {a, b};
    
    int g = gcd(n, m);
    int l = n / g * m;

    return {g, l};
}
