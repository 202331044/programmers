#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
//     queue <int> que1, que2;
//     int size = queue1.size();
//     long long sum1 = 0, sum2 = 0;
    
//     for(int i = 0; i < size; ++i)
//     {
//         que1.push(queue1[i]);
//         que2.push(queue2[i]);   
        
//         sum1 += queue1[i];
//         sum2 += queue2[i];
//     }
    
//     if((sum1 + sum2) % 2 != 0) return -1;
    
//     int cnt = 0;
//     while(cnt < 3 * size)
//     {
//         if(sum1 == sum2) return cnt;
        
//         if(sum1 < sum2)
//         {
//             int num = que2.front();
//             que2.pop();
//             que1.push(num);
            
//             sum1 += num;
//             sum2 -= num;
//         }
//         else
//         {
//             int num = que1.front();
//             que1.pop();
//             que2.push(num);
            
//             sum2 += num;
//             sum1 -= num;
//         }

//         cnt++;
//     }
    
//     return -1;
    
    long long total = 0, cur = 0;
    vector<int> arr;
    
    for(int x: queue1)
    {
        arr.push_back(x);
        cur += x;
        total += x;
    }
    
    for(int x: queue2)
    {
        arr.push_back(x);
        total += x;
    }
    
    if(total % 2 != 0) return -1;
    
    arr.insert(arr.end(), queue1.begin(), queue1.end());
    arr.insert(arr.end(), queue2.begin(), queue2.end());
    
    long long target = total / 2;
    int size = queue1.size();
    int l = 0, r = size;
    int cnt = 0;
    
    while(cnt < size * 3)
    {
        if(target == cur) return cnt;
        
        if(cur < target) cur += arr[r++];
        else cur -= arr[l++];
        
        cnt++;
    }
    
    return -1;
}
