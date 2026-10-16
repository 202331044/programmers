#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
//     int n = stones.size();
//     vector<int> broken(n + 2, 0);
//     priority_queue<pair<int, int>,
//                    vector<pair<int, int>>,
//                    greater<pair<int, int>>> pq;
    
//     for(int i = 0; i < n; ++i)
//         pq.push({stones[i], i + 1});
    
//     int answer = 0;

//     while(!pq.empty())
//     {
//         auto [count, idx] = pq.top();

//         pq.pop();
//         answer = count;
        
//         broken[idx] = broken[idx - 1] + broken[idx + 1] + 1;
        
//         for(int i = idx + 1; i <= n; ++i)
//         {
//             if(broken[i] == 0) break;
//             broken[i] = broken[idx];
//         }
        
//         for(int i = idx - 1; i >= 0; --i)
//         {
//             if(broken[i] == 0) break;
//             broken[i] = broken[idx];
//         }
        
//         if(broken[idx] >= k) return answer;
//     }
    
//     return answer;
    
    int answer = 0;
    int left = 1;
    int right = *max_element(stones.begin(), stones.end());
    
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        bool isStop = false;
        int cnt = 0;
        
        for(int stone: stones)
        {
            if(stone < mid)
                cnt++;
            else
                cnt = 0;
            
            if(cnt == k)
            {
                isStop = true;
                break;
            }
        }
        
        if(isStop)
            right = mid - 1;
        else
        {
            answer = mid;
            left = mid + 1;
        }
    }
    
    return answer;
}
