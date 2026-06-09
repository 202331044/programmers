#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    
    for(int num: arr)
        answer = lcm(answer, num);
    
    return answer;
}
