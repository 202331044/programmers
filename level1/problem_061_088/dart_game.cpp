#include <string>
#include <cctype>
#include <vector>

using namespace std;

int solution(string dartResult) {
//    string strNum;
//     int answer = 0;
//     int pre = 0, cur = 0;
    
//     for(char& ch: dartResult)
//     {
//         if(isdigit(ch)) strNum += ch;
//         else if(isalpha(ch))
//         {
//             if(pre != 0) answer += pre;
            
//             pre = cur;
//             cur = stoi(strNum);
//             strNum.clear();
            
//             if(ch == 'D') cur *= cur;
//             else if(ch == 'T') cur = cur * cur * cur;
//         }
//         else
//         {
//             if(ch == '*')
//             {
//                 cur *= 2;
//                 pre *= 2;
//             }
//             else
//                 cur = -cur;
//         }
//     }
    
//     answer += pre + cur;
    
    int answer = 0;
    vector<int> scores;
    string strNum;
    
    for(char& ch: dartResult)
    {
        if(isdigit(ch)) 
            strNum += ch;
        else if(isalpha(ch))
        {
            int num = stoi(strNum);
            strNum.clear();
            
            if(ch == 'D') num *= num;
            else if(ch == 'T') num = num * num * num;
            
            scores.push_back(num);
        }  
        else
        {
            if(ch == '*') 
            {
                scores.back() *= 2;
                
                if(scores.size() > 1)
                    scores[scores.size() - 2] *= 2;
            }
            else
                scores.back() *= -1;
        }
    }
    
    for(int score: scores)
        answer += score;
    
    return answer;
}
