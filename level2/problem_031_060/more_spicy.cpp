#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), 
                                                      scoville.end());

    int cnt = 0;
    
    while(pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        
        if(a >= K) return cnt;

        int b = pq.top();
        pq.pop();
        
        pq.push(a + b * 2);
        cnt++;
    }
    
    return pq.top() >= K ? cnt : -1;
}
