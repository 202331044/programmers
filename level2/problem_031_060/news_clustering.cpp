#include <string>
#include <unordered_map>
#include <cctype>
#include <cmath>

using namespace std;

int make_dict(unordered_map<string, int>& dict, string& str)
{
    int size = 0;
    string word;
    for(char ch: str)
    {
        ch = tolower(ch);
        
        if(isalpha(ch))
            word += ch;
        else
            word.clear();
        
        if(word.size() == 2)
        {
            dict[word]++;
            size++;
            word = word.back();
        }
    }
    
    return size;
}

int solution(string str1, string str2) {
    unordered_map<string, int> dict1, dict2;
    int size1 = make_dict(dict1, str1);
    int size2 = make_dict(dict2, str2);
    
    if(size1 == 0 && size2 == 0)
        return 65536;
    
    int cnt = 0;
    for(auto& it: dict1)
    {
        string key = it.first;
        int num = it.second;
        
        if(dict2.find(key) != dict2.end())
            cnt += min(num, dict2[key]);
    }
    
    double answer = static_cast<double>(cnt) / (size1 + size2 - cnt);

    return floor(answer * 65536);
}
