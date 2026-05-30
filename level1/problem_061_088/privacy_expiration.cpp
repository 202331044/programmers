#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// vector<int> toIntDate(string& str)
// {
//     vector<int> vec;
//     string tmp;
    
//     for(char& ch: str)
//     {
//         if(ch == '.')
//         {
//             vec.push_back(stoi(tmp));
//             tmp.clear();
//         }
//         else
//             tmp += ch;
//     }
    
//     vec.push_back(stoi(tmp));
    
//     return vec;
// }

// void calcNewDate(vector<int>& vec, int& range)
// {
//     vec[0] += (vec[1] - 1 + range)/ 12;
//     vec[1] = (vec[1] + range) % 12 == 0 ? 12 : (vec[1] + range) % 12;
    
//     if(vec[2] - 1 == 0)
//     {
//         vec[2] = 28;
        
//         if(vec[1] - 1 == 0)
//         {
//             vec[1] = 12;
//             vec[0]--;
//         }
//         else
//             vec[1]--;
//     }
//     else
//         vec[2]--;
// }

int toIntDate(string& str)
{
    istringstream iss(str);
    string token;
    vector<int> tmp;
    
    while(getline(iss, token, '.'))
        tmp.push_back(stoi(token));
    
    return tmp[0] * 28 * 12 + tmp[1] * 28 + tmp[2];
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
//     vector<int> answer;
//     unordered_map<char, int> um;
        
//     for(string& term: terms)
//     {
//         char type;
//         int range;
        
//         istringstream iss(term);
//         iss >> type >> range;
        
//         um[type] = range;
//     }
    
//     vector<int> newToday = toIntDate(today);
    
//     for(int i = 0; i < privacies.size(); ++i)
//     {
//         istringstream iss(privacies[i]);
//         string date;
//         char type;
        
//         iss >> date >> type;
//         vector<int> newDate = toIntDate(date);
//         calcNewDate(newDate, um[type]);
        
//         for(int k = 0; k < 3; ++k)
//         {
//             if(newDate[k] < newToday[k])
//             {
//                 answer.push_back(i+1);
//                 break;
//             }
//             else if(newDate[k] > newToday[k]) break;
//         }    
//     }
    
//     return answer;
    
    unordered_map<char, int> um;
    
    for(string& term: terms)
    {
        istringstream iss(term);
        char type;
        int range;
        
        iss >> type >> range;
        um[type] = range;
    }
    
    int iToday = toIntDate(today);
    vector<int> answer;
    
    for(int i = 0; i < privacies.size(); ++i)
    {
        string date;
        char type;
        
        istringstream iss(privacies[i]);
        iss >> date >> type;
        
        int curDate = toIntDate(date);
        curDate += um[type] * 28 - 1;
        if(curDate < iToday) answer.push_back(i+1);
    }
    
    return answer;
}
