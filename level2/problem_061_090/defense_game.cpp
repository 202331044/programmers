#include <string>
#include <vector>
#include <queue>


using namespace std;

int solution(int n, int k, vector<int> enemy) {
//     priority_queue<int> pq;

//     if(enemy.size() <= k) 
//         return enemy.size();
    
//     for(int i = 0; i < enemy.size(); ++i)
//     {
//         if(n >= enemy[i])
//         {
//             pq.push(enemy[i]);
//             n -= enemy[i];
//         }
//         else if(k > 0)
//         {
//             if(!pq.empty() && pq.top() > enemy[i])
//             {
//                 n += pq.top();
//                 pq.pop();
//                 n -= enemy[i];
//                 pq.push(enemy[i]);
//             }
//             k--;
//         }
//         else
//             return i;
//     }
    
//     return enemy.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < enemy.size(); ++i)
    {
        pq.push(enemy[i]);
        
        if(pq.size() > k)
        {
            n -= pq.top();
            pq.pop();
        }
        
        if(n < 0) return i;
    }
    
    return enemy.size();
}
