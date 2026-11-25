#include <string>
#include <vector>

using namespace std;

int count_110(string& str)
{
    int cnt = 0;
    string res;
    
    for(char ch: str)
    {
        res.push_back(ch);
        int size = res.size();
        
        if(size >= 3 && res.substr(size - 3, 3) == "110")
        {
            // res.pop_back();
            // res.pop_back();
            // res.pop_back();
            res.resize(size - 3);
            cnt++;
        }
    }
    
    str = res;
    return cnt;
}

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
//     for(string& str: s)
//     {
//         int cnt = count_110(str);
        
//         string add;
//         while(cnt--) add += "110";
        
//         string res;
//         for(int idx = 0; idx < str.size(); ++idx)
//         {
//             string sub = str.substr(idx, 2);
//             if("110" + sub < sub +  "110")
//             {
//                 res += add;
//                 add = "";
//                 res += str.substr(idx);
//                 break;
//             }
//             else
//                 res += str[idx];
//         }
        
//         res += add;
//         answer.push_back(res);
//     }
    
//     return answer;
    
    for(string& str: s)
    {
        int cnt = count_110(str);
        
        string add;
        while(cnt--) add += "110";
        
        int pos = str.find_last_of('0');
        if(pos == string::npos) str.insert(0, add);
        else str.insert(pos + 1, add);
        
        answer.push_back(str);
    }
    
    return answer;
}
