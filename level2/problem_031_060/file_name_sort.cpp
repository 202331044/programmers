#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct Name
{
    string head;
    int number;
};

Name split(string& file)
{
    string head, number;
    int idx = 0;
    
    for(char ch: file)
    {
        if(idx == 0 && isdigit(ch))
            idx = 1;
        else if(idx == 1 && (!isdigit(ch) || number.size() >= 5))
            break;
        
        if(idx == 0)
            head += tolower(ch);
        else if(idx == 1)
            number += ch;
    }
    
    return {head, stoi(number)};
}

struct FileInfo
{
    string file;
    string head;
    int number;
};

FileInfo to_info(const string& file)
{
    string head, number;
    bool isNumber = false;
    
    for(char ch: file)
    {
        if(!isNumber && isdigit(ch))
            isNumber = true;
        else if(isNumber && (!isdigit(ch) || number.size() >= 5))
            break;
        
        if(!isNumber)
            head += tolower(ch);
        else if(isNumber)
            number += ch;
    }
    
    return {file, head, stoi(number)};
}

vector<string> solution(vector<string> files) {
//     vector<pair<int, Name>> new_files;

//     for(int i = 0; i < files.size(); ++i)
//         new_files.push_back({i, split(files[i])});
 
    
//     sort(new_files.begin(), new_files.end(), [](const pair<int, Name>& a,
//                                                       const pair<int, Name>& b)
//                 {
//                     if(a.second.head != b.second.head) 
//                         return a.second.head < b.second.head;
//                     else if(a.second.number != b.second.number) 
//                         return a.second.number < b.second.number;
//                     else
//                         return a.first < b.first;
//                 });
    
//     vector<string> answer;
//     for(auto &it : new_files)
//         answer.push_back(files[it.first]);
    
//     return answer;
    
    vector<FileInfo> info;
    for(int i = 0; i < files.size(); ++i)
        info.push_back(to_info(files[i]));
    
    stable_sort(info.begin(), info.end(), [](const FileInfo& a, 
                                             const FileInfo& b)
                {
                    if(a.head != b.head) return a.head < b.head;
                    return a.number < b.number;
                });
        
    vector<string> answer;
    for(auto& it: info)
        answer.push_back(it.file);
    
    return answer;
}
