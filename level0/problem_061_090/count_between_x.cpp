#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    answer.reserve(myString.size());
    
    int size = 0;
    for(char ch: myString)
    {
        if(ch == 'x')
        {
            answer.push_back(size);
            size = 0;
        }
        else
            size++;
    }
    
    answer.push_back(size);
    
    return answer;
}
