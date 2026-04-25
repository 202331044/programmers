#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names) {
    vector<string> answer;
    int size = names.size();
    
    for(int i = 0; i < size; i += 5)
        answer.push_back(names[i]);

    return answer;
}
