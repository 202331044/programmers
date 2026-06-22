#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string digits = "0123456789ABCDEF";

string make_nth(int n, int num)
{
    if(num == 0) return "0";
    
    string str;
    while(num)
    {
        int r = num % n;
        str += digits[r];
        // str += r < 10 ? r + '0' : ('A' - 10 + r);
        num /= n;
    }
    
    reverse(str.begin(), str.end());
    return str;
}

string solution(int n, int t, int m, int p) {
//     string turns;
//     int num = 0;
    
//     while(turns.size() < (t - 1) * m + p)
//     {
//         string str = make_nth(n, num);
//         turns += str;
//         num++;
//     }
    
//     string answer;
//     for(int i = p - 1; i < (t - 1) * m + p; i += m)
//         answer += turns[i];
    
//     return answer;
    
    int num = 0, turn = 0;
    string answer;
    
    while(answer.size() < t)
    {
        string str = make_nth(n, num++);
        for(char ch: str)
        {
            if(answer.size() == t) 
                return answer;
            
            if(turn % m == p - 1)
                answer.push_back(ch);
            
            turn++;
        }
    }
    
    return answer;
}
