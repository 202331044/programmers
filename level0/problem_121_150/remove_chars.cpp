#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    
    for(int idx: indices)
        my_string[idx] = '0';
    
    for(char ch: my_string)
        if(ch != '0') answer += ch;
    
    return answer;
}
