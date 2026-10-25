#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
//     priority_queue<int, vector<int>, greater<int>> pq;
    
//     for(string& time: timetable)
//     {
//         int tmp = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
//         pq.push(tmp);
//     }
    
//     int answer = 0;
//     int curN = 0;
//     int curTime = 9 * 60;

//     while(!pq.empty() && curN < n)
//     {
//         int cnt = 0;
//         int preTime = 0;

//         while(!pq.empty() && cnt < m)
//         {
//             int cur = pq.top();

//             if(cur <= curTime)
//             {
//                 cnt++;
//                 preTime = cur;
//                 pq.pop();
//             }
//             else 
//                 break;
//         }
        
//         if(cnt < m) 
//             answer = max(answer, curTime);
//         else 
//             answer = max({preTime - 1, 0, answer});
        
//         curTime += t;
//         curN++;
//     }
    
//     string hour = to_string(answer / 60);
//     if(hour.size() == 1) 
//         hour = '0' + hour;
    
//     string minute = to_string(answer % 60);
//     if(minute.size() == 1) 
//         minute = '0' + minute;

//     return hour + ":" + minute;
    
    vector<int> crew;
    
    for(string& time: timetable)
    {
        crew.push_back(stoi(time.substr(0, 2)) * 60 
                       + stoi(time.substr(3, 2)));
    }
    
    sort(crew.begin(), crew.end());
    
    int k = crew.size();
    int idx = 0;
    int answer = 0;
    
    for(int bus = 0; bus < n; ++bus)
    {
        int busTime = 9 * 60 + bus * t;
        int cnt = 0;
        
        while(idx < k && crew[idx] <= busTime && cnt < m)
        {
            cnt++;
            idx++;
        }
        
        if(cnt < m) 
            answer = busTime;
        else 
            answer = crew[idx - 1] - 1;
    }
    
    string hour = to_string(answer / 60);
    string minute = to_string(answer % 60);
    
    hour = hour.size() == 1 ? '0' + hour : hour;
    minute = minute.size() == 1 ? '0' + minute : minute;
        
    return hour + ":" + minute;
}
