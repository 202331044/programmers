#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
//     int dp = n - 1;
//     int pp = n- 1;
//     long long answer = 0;
    
//     while(dp >= 0 || pp >= 0)
//     {
//         int dist = 0;
//         int limits = 0;
        
//         while(dp >= 0 && limits < cap)
//         {
//             limits += deliveries[dp];
//             if(deliveries[dp] != 0)
//                 dist = max(dist, dp + 1);
            
//             deliveries[dp] = 0;  
//             dp--;
                  
//             if(limits > cap)
//             {
//                 dp++;
//                 deliveries[dp] = limits - cap;
//                 break;
//             }
//         }
        
//         limits = cap;
//         while(pp >= 0 && limits > 0)
//         {
//             limits -= pickups[pp];
            
//             if(pickups[pp] != 0)
//                 dist = max(dist, pp + 1);
             
//             pickups[pp] = 0; 
//             pp--;
   
//             if(limits < 0)
//             {
//                 pp++;
//                 pickups[pp] = -limits;
//                 break;
//             }
//         }

//         answer += (dist * 2);
//     }
    
    long long answer = 0;
    int delivery = 0;
    int pickup = 0;
    
    for(int i = n - 1; i >= 0; --i)
    {
        delivery += deliveries[i];
        pickup += pickups[i];
        
        while(delivery > 0 || pickup > 0)
        {
            answer += (i + 1) * 2;
            delivery -= cap;
            pickup -= cap;
        }
    }
    
    return answer;
}
