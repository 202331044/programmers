#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<string> data) {
//     string str = "ACFJMNRT";
//     vector<string> cases;
//     cases.push_back(str);
    
//     while(next_permutation(str.begin(), str.end()))
//         cases.push_back(str);
    
//     for(auto& condition: data)
//     {
//         char from = condition[0];
//         char to = condition[2];
//         char op = condition[3];
//         int dist = condition[4] - '0';
        
//         vector<string> new_cases;

//         for(auto& curStr: cases)
//         {
//             int p1, p2;
            
//             for(int idx = 0; idx < 8; ++idx)
//             {
//                 if(curStr[idx] == from)
//                     p1 = idx;
//                 if(curStr[idx] == to)
//                     p2 = idx;
//             }
            
//             int diff = abs(p1 - p2) - 1;
            
//             if(op == '=' && dist == diff)
//                 new_cases.push_back(curStr);
//             else if(op == '<' && diff < dist)
//                 new_cases.push_back(curStr);
//             else if(op == '>' && diff > dist)
//                 new_cases.push_back(curStr);
//         }
        
//         cases = new_cases;
//     }
    
//     return cases.size();
    
    int answer = 0;
    string str = "ACFJMNRT";
    
    do
    {
        bool isValid = true;
        
        for(auto& condition: data)
        {
            char from = condition[0];
            char to = condition[2];
            char op = condition[3];
            int dist = condition[4] - '0';
            
            int p1, p2;
            
            for(int idx = 0; idx < 8; ++idx)
            {
                if(str[idx] == from) p1 = idx;
                else if(str[idx] == to) p2 = idx;
            }
            
            int diff = abs(p1 - p2) - 1;
            
            if( (op == '=' && dist != diff) ||
                (op == '<' && diff >= dist) ||
                (op == '>' && diff <= dist))
            {
                isValid = false;
                break;
            }
        }
        
        if(isValid) answer++;
        
    } while(next_permutation(str.begin(), str.end()));
    
    return answer;
}
