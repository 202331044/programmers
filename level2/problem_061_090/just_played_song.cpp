#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cctype>
#include <sstream>

using namespace std;

string convert_from_sharp(string& str)
{
    string new_str;
    for(char& ch: str)
    {
        if(ch == '#')
        {
            char new_ch = tolower(new_str.back());
            new_str.pop_back();
            new_str.push_back(new_ch);
        }
        else
            new_str.push_back(ch);
    }
    
    return new_str;
}

vector<string> split_info(string& musicinfo)
{
    vector<string> infos;
    string tmp;

    for(char& ch: musicinfo)
    {
        if(ch == ',')
        {
            infos.push_back(tmp);
            tmp = "";
        }
        else
            tmp.push_back(ch);
    }

    infos.push_back(tmp);
    
    return infos;
}

int convert_time(string& start, string& end)
{
    int time = (stoi(end.substr(0, 2)) * 60 + stoi(end.substr(3, 2))) 
    - (stoi(start.substr(0, 2)) * 60 + stoi(start.substr(3, 2)));
    
    return time;
}

string solution(string m, vector<string> musicinfos) {
//     string new_m = convert_from_sharp(m);
//     vector<pair<string, int>> answer;
    
//     for(string& musicinfo: musicinfos)
//     {
//         vector<string> infos;
//         infos = split_info(musicinfo);
        
//         string start = infos[0];
//         string end = infos[1];
//         string title = infos[2];
//         string record = infos[3];

//         record = convert_from_sharp(record);
//         int time = convert_time(start, end);

//         string full_music;
//         for(int i = 0; i < time; ++i)
//             full_music.push_back(record[i%record.size()]);
        
//         if(full_music.find(new_m) != string::npos)
//             answer.emplace_back(title, time);
//     }
    
//     if(answer.empty()) return "(None)";

//     if(answer.size() > 1)
//     {
//         stable_sort(answer.begin(), answer.end(), 
//                     [](const pair<string, int>& a, const pair<string, int>& b)
//                     {
//                         return a.second > b.second;
//                     });
//     }
    
//     return answer[0].first;
    
    string new_m = convert_from_sharp(m);
    string answer;
    int maxTime = -1;
    
    for(string& musicinfo: musicinfos)
    {
        vector<string> infos;
        stringstream ss(musicinfo);
        string token;
        
        while(getline(ss, token, ','))
            infos.push_back(token);
        
        int time = convert_time(infos[0], infos[1]);
        if(time <= maxTime) continue;
        
        string record = convert_from_sharp(infos[3]);
        string new_record;
        for(int i = 0; i < time; ++i)
            new_record.push_back(record[i % record.size()]);
        
        if(new_record.find(new_m) != string::npos)
        {
            answer = infos[2];
            maxTime = time;
        }
    }
    
    if(maxTime > 0) return answer;
    return "(None)";
}
