#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<int> players, int m, int k) {
//     int answer = 0, server = 0;
//     queue<pair<int, int>> que;
    
//     for(int i = 0; i < players.size(); ++i)
//     {
//         if(!que.empty() && que.front().second <= i) 
//         {
//             server -= que.front().first;
//             que.pop();
//         }
        
//         int num = players[i] / m;
        
//         if(num > server)
//         {
//             que.push({num - server, i + k});
//             answer += num - server;
//             server = num;
//         }
//     }
    
//     return answer;
    
    int answer = 0, servers = 0;
    vector<int> expire(players.size() + k + 1, 0);
    
    for(int i = 0; i < players.size(); ++i)
    {
        servers -= expire[i];
        int need = players[i] / m;

        if(need > servers)
        {
            int add = need - servers;
            
            expire[i + k] = add;
            answer += add;
            servers += add;
        }
    }
    
    return answer;
}
