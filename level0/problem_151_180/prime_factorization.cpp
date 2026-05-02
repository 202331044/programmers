#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n) {
//     set<int> s;
    
//     int i = 2;
//     while(n > 1)
//     {
//         if(n % i == 0) 
//         {
//             s.insert(i);
//             n /= i;
//         }
//         else i++;
//     }
    
//     return vector<int>(s.begin(), s.end());
    
    vector<int> answer;
    
    for(int i = 2; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            answer.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    
    if(n > 1) answer.push_back(n);
    
    return answer;
}
