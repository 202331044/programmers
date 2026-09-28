#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    const int MAX = 50000;
    
    vector<int> count(MAX + 1, 0);
    
    for(int work: works)
        count[work]++;
    
    for(int i = MAX; i > 0; --i)
    {
        if(n == 0) break;
        
        if(count[i] != 0)
        {
            int num = min(n ,count[i]);
            
            count[i - 1] += num;
            n -= num;
            count[i] -= num;
            
        }
    }
    
    long long answer = 0;
    
    for(int i = 1; i <= MAX; ++i)
        answer += i * i * count[i];
    
    return answer;
    
//     priority_queue<int> pq;
    
//     for(int work: works)
//         pq.push(work);
       
//     while(n--)
//     {
//         int cur = pq.top();
//         pq.pop();
        
//         if(cur == 0) break;
        
//         cur--;
//         pq.push(cur);
//     }
    
//     long long answer = 0;
    
//     while(!pq.empty())
//     {
//         int cur = pq.top();
//         pq.pop();
//         answer += cur * cur;
//     }
    
//     return answer;
}
