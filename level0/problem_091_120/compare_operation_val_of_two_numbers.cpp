#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string num = to_string(a) + to_string(b);
    
    int answer = stoi(num) > 2 * a * b ? stoi(num) : 2 * a * b;
    
    return answer;
}
