#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    string str = "";
    
    for(char ch: myString)
    {
        if(ch != 'x') str += ch;
        else
        {
            if(!str.empty()) answer.push_back(str);
            str = "";
        }
    }
    
    if(!str.empty()) answer.push_back(str);
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
