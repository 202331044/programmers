#include <numeric>

using namespace std;

long long solution(int w,int h) {
    long long nw = w, nh = h;
    return nw * nh - (nw + nh - gcd(nw, nh));
}
