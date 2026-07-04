#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    
//     unordered_map<string, string> um;
    
//     for(const string& str: record)
//     {
//         istringstream iss(str);
//         string state, id, name;
//         iss >> state >> id >> name;
        
//         if(!name.empty())
//             um[id] = name;
//     }
    
//     vector<string> answer;
//     for(const string& str: record)
//     {
//         istringstream iss(str);
//         string state, id, name;
//         iss >> state >> id >> name;
        
//         if(state == "Enter")
//             answer.push_back(um[id] + "님이 들어왔습니다.");
//         else if(state == "Leave")
//             answer.push_back(um[id] + "님이 나갔습니다.");
//     }
    
//     return answer;
    
    unordered_map<string, string> um;
    vector<pair<string, string>> events;
    
    for(const string& str: record)
    {
        istringstream iss(str);
        string state, id, name;
        iss >> state >> id >> name;
        
        if(state != "Change") 
            events.emplace_back(state, id);
        if(!name.empty()) 
            um[id] = name;
    }
    
    vector<string> answer;
    answer.reserve(events.size());
    
    for(const auto& [state, id]: events)
    {
        if(state == "Enter")
            answer.push_back(um[id] + "님이 들어왔습니다.");
        else if(state == "Leave")
            answer.push_back(um[id] + "님이 나갔습니다.");
    }
    
    return answer;
}
