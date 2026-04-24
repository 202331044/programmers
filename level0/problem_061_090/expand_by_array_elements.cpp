#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for(int num: arr)
        answer.insert(answer.end(), num, num);
    
    return answer;
}
