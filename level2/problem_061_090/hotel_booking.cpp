#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;

int convert_time(const string& str)
{
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
}

int solution(vector<vector<string>> book_time) {
//     vector<pair<int, int>> vec;
    
//     for(auto times: book_time)
//     {
//         string in = times[0];
//         string out = times[1];
        
//         vec.emplace_back(0, stoi(in.substr(0, 2)) * 60 +
//                             stoi(in.substr(3, 2)));
//         vec.emplace_back(1, stoi(out.substr(0, 2)) * 60 +
//                             stoi(out.substr(3, 2)) + 10);
//     }
    
//     sort(vec.begin(), vec.end(), [](const pair<int, int>& a, 
//                                     const pair<int, int>& b)
//          {
//              if(a.second != b.second) return a.second < b.second;
//              else return a.first > b.first;    
//          });
    
//     int cnt = 0, answer = 0;
//     for(auto [state, time]: vec)
//     {
//         if(state == 0)
//         {
//             cnt++;
//             answer = max(answer, cnt);
//         }
//         else
//             cnt--;
//     }
    
//     return answer;
    
    vector<pair<int, int>> vec;
    
    for(auto& it: book_time)
    {
        int inTime = convert_time(it[0]);
        int outTime = convert_time(it[1]) + 10;
        
        vec.emplace_back(inTime, outTime);
    }
    
    sort(vec.begin(), vec.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto [inTime, outTime]: vec)
    {
        if(!pq.empty() && pq.top() <= inTime) pq.pop();
        pq.push(outTime);

    }
    
    return pq.size();
}
