#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c) {
    
    int s1 = (a + b + c);
    int s2 = (a*a + b*b + c*c);
    int s3 = (a*a*a + b*b*b + c*c*c);
    
    if(a == b && b == c) return  s1 * s2 * s3;
    if(a != b && a != c && b != c) return s1;
    else return s1 * s2;
}
