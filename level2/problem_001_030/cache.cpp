#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
//     int size = 0;
//     int time = 0;
    
//     queue <pair<string, int>> que;
//     unordered_map<string, int> um;
    
//     for(int i = 0; i < cities.size(); ++i)
//     {
//         string city = cities[i];
        
//         transform(city.begin(), city.end(), city.begin(), [](char& ch)
//                   {
//                       return tolower(ch);
//                   });
        
//         if(um[city] == 0)
//         {
//             size++;
//             time += 5;
//         }
//         else
//             time += 1;
        
//         um[city] = i + 1;
//         que.push({city, i + 1});
        
//         if(size > cacheSize)
//         {
//             while(!que.empty())
//             {
//                 auto& cur = que.front();
//                 que.pop();
                
//                 if(um[cur.first] == cur.second)
//                 {
//                     size--;
//                     um[cur.first] = 0;
//                     break;
//                 }
//             }
//         }
//     }
    
//     return time;
    
    int time = 0;
    list<string> lst;
    unordered_map<string, list<string>::iterator> um;
    
    for(string& city: cities)
    {
        transform(city.begin(), city.end(), city.begin(), [](unsigned char ch)
          {
              return tolower(ch);
          });
        
        auto it = um.find(city);
        if(it == um.end())
        {
            time += 5;
            lst.push_front(city);
            um.emplace(city, lst.begin());
            
            if(lst.size() > cacheSize)
            {
                um.erase(lst.back());
                lst.pop_back();
            }
        }
        else
        {
            time++;
            lst.splice(lst.begin(), lst, it->second);
        }
    }
    
    return time;
}
