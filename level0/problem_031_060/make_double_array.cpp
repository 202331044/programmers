#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    // for(auto num: numbers)
    //     answer.push_back(num*2);
    
    transform(numbers.begin(), numbers.end(), back_inserter(answer),
             [](int x) {return x * 2;});
    
    return answer;
}
