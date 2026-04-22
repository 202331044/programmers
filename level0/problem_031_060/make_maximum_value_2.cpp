#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), greater<int>());
    
    int num1 = numbers[0] * numbers[1];
    int num2 = numbers[numbers.size()-1] * numbers[numbers.size() - 2];
    int answer = num1 > num2 ? num1 : num2;
    
    return answer;
}
