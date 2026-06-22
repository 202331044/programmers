#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    unordered_map<string, int> dict;
    for(int i = 0; i < 26; ++i)
    {
        string a = string(1, 'A' + i);
        dict[a] = i + 1;
    }
        
    int idx = 27;
    string str;
    vector<int> answer;
    
    for(char ch: msg)
    {   
       if(dict.find(str + ch) != dict.end())
            str += ch;
        else
        {
            answer.push_back(dict[str]);
            dict[str + ch] = idx++;
            str = ch;
        }
    }
    
    answer.push_back(dict[str]);
    return answer;
}
