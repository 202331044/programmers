#include <string>
#include <vector>

using namespace std;

int convert_to_int(const string& str)
{
    int time = stoi(str.substr(0, 2)) * 60 * 60 
                + stoi(str.substr(3, 2)) * 60 
                + stoi(str.substr(6, 2));
    
    return time;
}

string convert_to_string(int time)
{
    string answer;
    int h = (time / 3600);
    int m = (time % 3600) / 60;
    int s = time % 60;
    
//     string hour = h < 10 ? "0" + to_string(h) : to_string(h);
//     answer += hour + ":";
    
//     string minute = m < 10 ? "0" + to_string(m) : to_string(m);
//     answer += minute + ":";
    
//     string second = s < 10 ? "0" + to_string(s) : to_string(s);
//     answer += second;
    
    auto get_str = [](int n)
    {
        if(n < 10) return "0" + to_string(n);
        return to_string(n);
    };
    
    answer += get_str(h);
    answer += ":";
    answer += get_str(m);
    answer += ":";
    answer += get_str(s);
    
    return answer;
}

string solution(string play_time, string adv_time, vector<string> logs) {
//     int play = convert_to_int(play_time);
//     int ad = convert_to_int(adv_time);
    
//     const int MAX = play;
//     vector<long long> counts(MAX + 1, 0);
        
//     for(string& log: logs)
//     {
//         int start = convert_to_int(log.substr(0, 8));
//         int end = convert_to_int(log.substr(9, 8));
        
//         counts[start]++;
//         counts[end]--;
//     }
    
//     for(int i = 1; i <= MAX; ++i)
//         counts[i] += counts[i - 1];
//     for(int i = 1; i <= MAX; ++i)
//         counts[i] += counts[i - 1];
    
//     int startTime = 0;
//     long long cumlCnt = counts[ad - 1];
//     long long maxCnt = cumlCnt;
//     int idx = 0;
    
//     for(int i = ad; i < MAX; ++i)
//     {
//         cumlCnt = counts[i] - counts[i - ad];
//         idx++;

//         if(maxCnt < cumlCnt)
//         {
//             startTime = idx;
//             maxCnt = cumlCnt;
//         }
//     }

//     return convert_to_string(startTime);
    
    int play = convert_to_int(play_time);
    int ad = convert_to_int(adv_time);
    
    const int MAX = play;
    vector<int> views(MAX + 1, 0);
    
    for(const string& log: logs)
    {
        int start = convert_to_int(log.substr(0, 8));
        int end = convert_to_int(log.substr(9, 8));
        
        views[start]++;
        views[end]--;
    }
    
    for(int i = 1; i <= MAX; ++i)
        views[i] += views[i - 1];
    
    vector<long long> prefix_sum(MAX + 1, 0);
    
    for(int i = 0; i < MAX; ++i)
        prefix_sum[i + 1] = prefix_sum[i] + views[i];
    
    int startTime = 0;
    long long maxView = prefix_sum[ad];
    
    for(int i = 1; i + ad <= MAX; ++i)
    {
        long long curView = prefix_sum[i + ad] - prefix_sum[i];
        
        if(maxView < curView)
        {
            maxView = curView;
            startTime = i;
        }
    }
    
    return convert_to_string(startTime);
}
