#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
//     int idx = 0, s = 0, size = 0;
    
//     while(idx < my_string.size())
//     {
//         if(my_string[idx] != ' ')
//             size++;
//         else
//         {
//             answer.push_back(my_string.substr(s, size));
//             s = idx + 1;
//             size = 0;
//         }
//         idx++;
//     }
    
//     answer.push_back(my_string.substr(s, size));
    
    string tmp = "";
    
    for(char ch: my_string)
    {
        if(ch == ' ')
        {
            if(!tmp.empty()) answer.push_back(tmp);
            tmp.clear();
        }
        else tmp += ch;
    }
    
    answer.push_back(tmp);
    
    return answer;
}
