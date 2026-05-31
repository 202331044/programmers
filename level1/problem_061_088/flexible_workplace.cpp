#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int n = schedules.size();
    
    for(int& time: schedules)
    {
        int h = time / 100;
        int m = time % 100;
        time = h * 60 + m + 10;
    }
    
    for(int i = 0; i < n; ++i)
    {
        int cnt = 0;
        for(int j = 0; j < 7; ++j)
        {
            if((startday - 1 + j) % 7 + 1 >= 6) continue;
            
            int h = timelogs[i][j] / 100;
            int m = timelogs[i][j] % 100;

            if(h * 60 + m <= schedules[i]) cnt++;
        }
        
        if(cnt >= 5) answer++;
    }
    
    return answer;
}
