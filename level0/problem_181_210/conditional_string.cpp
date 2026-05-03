#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    
    if(ineq == ">" && eq == "=")
        return (n > m || n == m);
    if(ineq == ">" && eq == "!")
        return n > m;
    if(ineq == "<" && eq == "=")
        return (n < m || n == m);
    if(ineq == "<" && eq == "!")
        return n < m;
    
    return 0;
}
