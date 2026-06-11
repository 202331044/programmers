#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
//     vector<int> answer;
//     int n = progresses.size(), s = 0;
    
//     while(s < n)
//     {
//         int days = (100 - progresses[s]) / speeds[s];
//         days += ((100 - progresses[s]) % speeds[s] == 0) ? 0 : 1;
        
//         for(int i = s; i < n; ++i)
//             progresses[i] += days * speeds[i];
        
//         int cnt = 0;
//         while(s < n && progresses[s] >= 100)
//         {
//             s++;
//             cnt++;
//         }
        
//         answer.push_back(cnt);   
//     }
    
//     return answer;
    
    for(int i = 0; i < progresses.size(); ++i)
    {
        int days = (100 - progresses[i] + speeds[i] - 1) / speeds[i];
        progresses[i] = days;
    }
    
    vector<int> answer;
    int deployDay = progresses[0];
    int cnt = 1;
    
    for(int j = 1; j < progresses.size(); ++j)
    {
        if(deployDay < progresses[j])
        {
            answer.push_back(cnt);
            cnt = 1;
            deployDay = progresses[j];
        }
        else
            cnt++;
    }

    answer.push_back(cnt);
    return answer;
}
