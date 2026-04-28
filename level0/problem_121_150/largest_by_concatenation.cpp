#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string strA = to_string(a), strB = to_string(b);
    
    return strA + strB >= strB + strA ? stoi(strA + strB) : stoi(strB + strA);
}
