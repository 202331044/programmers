#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
//     int answer = 0;
//     stack<int> stk;
    
//     for(int& i: ingredient)
//     {
//        if(stk.empty())
//        {
//            if(i == 1) stk.push(i);
//        }
//        else
//        {
//            if(i == 1 && stk.top() == 3)
//            {
//                for(int j = 0; j < 3; ++j)
//                    stk.pop();
               
//                 answer++;
//            }
//            else if((stk.top() + 1 == i) || i == 1)
//                stk.push(i);
//            else
//                stk = stack<int>();
//        }
//     }
    
//     return answer;
    
    int answer = 0;
    vector<int> tmp;
    
    for(int i: ingredient)
    {
        tmp.push_back(i);
        int n = tmp.size();
        
        if(n > 3 && tmp[n - 1] == 1 && tmp[n - 2] == 3 &&
                    tmp[n - 3] == 2 && tmp[n - 4] == 1)
        {
            answer++;
            
            for(int j = 0; j < 4; ++j)
                tmp.pop_back();
        }
    }
    
    return answer;
}
