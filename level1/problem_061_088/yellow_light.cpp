#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<vector<int>> signals) {
    
//     vector<pair<int ,int>> vec;
//     int MAX = 10000000;
    
    
//     vector<int> count(MAX + 1, 0);
//     for(auto& signal: signals)
//     {
//         int start = signal[0] + 1;
//         int term = signal[0] + signal[1] + signal[2];
//         int range = signal[1];
        
//         for(int i = start; i <= MAX; i += term)
//         {
//             for(int j = i; j <= i + range - 1; ++j)
//                 count[j]++;
//         }      
//     }
    
//     for(int i = 0; i <= MAX; ++i)
//     {  
//         if(count[i] == signals.size()) 
//             return i;
//     }
    
//     return -1;
    
    
    int len = signals[0][0] + signals[0][1] + signals[0][2];
    
    for(int i = 1; i < signals.size(); ++i)
        len = lcm(len, signals[i][0] + signals[i][1] + signals[i][2]);
    
//     vector<int> vec(len + 1, 0);
    
//     for(auto& signal: signals)
//     {
//         int green = signal[0];
//         int yellow = signal[1];
//         int red = signal[2];
//         int range = green + yellow + red;
        
//         for(int i = green + 1; i <= len; i += range)
//         {
//             for(int j = i; j < i + yellow; ++j)
//                 vec[j]++;
//         }
//     }
    
//     for(int k = 0; k <= len; ++k)
//     {
//         if(vec[k] == signals.size())
//             return k;
//     }
    
//     return -1;
    
    vector<int> range;
    for(int i = 0; i < signals.size(); ++i)
        range.push_back(signals[i][0] + signals[i][1] + signals[i][2]);
    
    for(int t = 0; t <= len; ++t)
    {
        bool isTrue = true;
        
        for(int j = 0; j < range.size(); ++j)
        {
            if(signals[j][0] + 1 > t % range[j] ||
               signals[j][0] + signals[j][1] < t % range[j])
            {
                isTrue = false;
                break;
            }
        }
        
        if(isTrue) return t;
    }
    
    return -1;
}
