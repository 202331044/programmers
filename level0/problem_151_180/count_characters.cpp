#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52, 0);
    
    for(char& ch: my_string)
    {
        if(islower(ch)) answer[ch - 'a' + 26]++;
        else answer[ch - 'A']++;
    }
    
    return answer;
}
