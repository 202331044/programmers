#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(const string& str: babbling)
    {
        string pre;
        int s = 0;
        bool can = true;
        
        while(s < str.size())
        {
            string tmp1 = str.substr(s, 3);
            string tmp2 = str.substr(s, 2);
            if((tmp1 == "aya" || tmp1 == "woo") && pre != tmp1)
            {
                pre = tmp1;
                s += 3;
            }
            else if((tmp2 == "ye" || tmp2 == "ma") && pre != tmp2)
            {
                pre = tmp2;
                s += 2;
            }
            else
            {
                can = false;
                break;
            }
        }
        
        if(can) answer++;
    }
    return answer;
}
