#include <string>
#include <vector>

using namespace std;

int solution(string number) {
    int sum = 0;
    
    for(char ch: number)
        sum += ch - '0';

    return sum % 9;
}
