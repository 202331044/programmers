#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

long long solution(int a, int b) {
    return static_cast<long long> ((a + b)) * (abs(b - a) + 1) / 2;
}
