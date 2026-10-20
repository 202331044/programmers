#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int solution(vector<vector<int>> jobs) {
//     priority_queue<tuple<int, int, int>, 
//     vector<tuple<int, int, int>>,
//     greater<tuple<int, int, int>>> earlystart;
    
//     for(int i = 0; i < jobs.size(); ++i)
//         earlystart.push({jobs[i][0], jobs[i][1], i});
    
//     int total_time = 0;
//     int curTime = 0;
    
//     priority_queue<tuple<int, int, int>, 
//     vector<tuple<int, int, int>>,
//     greater<tuple<int, int, int>>> shortJobs;
    
//     while(!earlystart.empty())
//     {
//         auto cur = earlystart.top();
//         earlystart.pop();
        
//         int start = get<0>(cur);
//         int time = get<1>(cur);
//         int idx = get<2>(cur);
        
//         if(curTime < start)
//         {
//             while(!shortJobs.empty() && curTime < start)
//             {
//                 auto tmp = shortJobs.top();
//                 shortJobs.pop();
                
//                 int t = get<0>(tmp);
//                 int s = get<1>(tmp);
//                 int i = get<2>(tmp);

//                 total_time += (curTime + t - s);
//                 curTime += t;
//             }
            
//             curTime = max(start, curTime);
//         }
        
//         shortJobs.push({time, start, idx});
//     }
    
//     while(!shortJobs.empty())
//     {
//         auto tmp = shortJobs.top();
//         shortJobs.pop();

//         int t = get<0>(tmp);
//         int s = get<1>(tmp);
//         int i = get<2>(tmp);

//         total_time += (curTime + t - s);
//         curTime += t;
//     }
    
//     return total_time / jobs.size();
    
    
    vector<vector<int>> sorted_jobs;
    
    for(int i = 0; i < jobs.size(); ++i)
        sorted_jobs.push_back({jobs[i][0], jobs[i][1], i});
    
    sort(sorted_jobs.begin(), sorted_jobs.end());
    
    int curtime = 0;
    int total_time = 0;
    int n = sorted_jobs.size();
    int idx = 0;
    
    priority_queue<tuple<int, int, int>, 
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>
    > pq;
    
    while(!pq.empty() || idx < n)
    {
        while(idx < n && curtime >= sorted_jobs[idx][0])
        {
            pq.push({sorted_jobs[idx][1], 
                     sorted_jobs[idx][0], 
                     sorted_jobs[idx][2]});
            idx++;
        }
        
        if(!pq.empty())
        {
            auto [duration, start, id] = pq.top();
            pq.pop();
            
            curtime += duration;
            total_time += curtime - start;
        }
        else
            curtime = sorted_jobs[idx][0];
    }
    
    return total_time / n;
}
