#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cctype>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
//     vector<vector<int>> answer;
    
//     for(int i = 1; i < s.size() - 1; ++i)
//     {
//         if(s[i] == '{')
//         {
//             vector<int> tmp;
//             string num;
            
//             for(int j = i + 1; ; ++j)
//             {
//                 if(s[j] == '}')
//                 {
//                     tmp.push_back(stoi(num));
//                     break;
//                 }
//                 else if(s[j] == ',')
//                 {
//                     tmp.push_back(stoi(num));
//                     num.clear();
//                 }
//                 else
//                     num += s[j];
//             }
            
//             answer.push_back(tmp);
//         }
//     }
    
//     sort(answer.begin(), answer.end(), [](const vector<int>& a, 
//                                           const vector<int>& b)
//          {
//              return a.size() < b.size();
//          });
    
//     vector<int> res;
//     unordered_set<int> us;
//     for(auto& ans: answer)
//     {
//         for(auto& n: ans)
//         {
//             if(us.find(n) == us.end())
//             {
//                 us.insert(n);
//                 res.push_back(n);
//             }
//         }
//     }
    
//     return res;
    
    string num;
    unordered_map<int, int> um;

    for(char& ch: s)
    {
        if(isdigit(ch))
            num += ch;
        else if(!num.empty())
        {   
            um[stoi(num)]++;
            num.clear();
        }
    }
    
    int size = um.size();
    vector<int> answer(size, 0);
    for(auto& it: um)
    {
        answer[size - it.second] = it.first;
    };

    return answer; 
}
