#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> s;
    int size = numbers.size();
    
    for(int i = 0; i < size - 1; ++i)
        for(int j = i + 1; j < size; ++j)
            s.insert(numbers[i] + numbers[j]);
    
    vector<int> answer(s.begin(), s.end());
    return answer;
}
