#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    
    int sum =  (total * 2) / num;
    int s = (sum - num + 1)/2;
    int e = s + num - 1;
    
    for(int i = s; i <= e; ++i)
        answer.push_back(i);
    
    return answer;
}
