#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
//     int time = 0, totalW = 0;
//     queue<int> que;
    
//     for(int truck: truck_weights)
//     {
//         if(que.empty())
//         {
//             que.push(truck);
//             totalW += truck;
//             time++;
//         }
//         else if(totalW + truck <= weight)
//         {
//             que.push(truck);
//             totalW += truck;
//             time++;
//         }
//         else
//         {
//             if(que.size() == bridge_length)
//             {
//                 totalW -= que.front();
//                 que.pop();
//             }
            
//             while(totalW + truck > weight)
//             {
//                 que.push(0);
//                 time++;
                
//                 if(que.size() == bridge_length)
//                 {
//                     totalW -= que.front();
//                     que.pop();
//                 }
//             }
            
//             que.push(truck);
//             time++;
//             totalW += truck;
//         }
//     }
    
//     return time + bridge_length;
    
    queue<int> bridge;
    for(int i = 0; i < bridge_length; ++i)
        bridge.push(0);
    
    int idx = 0, total = 0, time = 0;
    while(idx < truck_weights.size())
    {
        total -= bridge.front();
        bridge.pop();
        time++;
        
        if(total + truck_weights[idx] <= weight)
        {
            bridge.push(truck_weights[idx]);
            total += truck_weights[idx];
            idx++;
        }
        else
            bridge.push(0);
    }
    
    return time + bridge_length;
}
