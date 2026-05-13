#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> lines) {
//     int answer = 0;
//     vector<int> count(201, 0);
    
//     for(auto& line: lines)
//     {
//         int s = line[0], e = line[1];
//         for(int i = s + 100; i < e + 100; ++i)
//             count[i]++;
//     }
    
//     for(int j = 0; j <= 200; ++j)
//         if(count[j] > 1) answer++; 
    
//     return answer;
    
    int answer = 0;
    
    answer += max(0, min(lines[0][1], lines[1][1]) - max(lines[0][0], lines[1][0]));
    answer += max(0, min(lines[1][1], lines[2][1]) - max(lines[1][0], lines[2][0]));
    answer += max(0, min(lines[0][1], lines[2][1]) - max(lines[0][0], lines[2][0]));

    
    answer -= 2 * max(0, min({lines[0][1], lines[1][1], lines[2][1]}) - max({lines[0][0], lines[1][0], lines[2][0]}));
   
    return answer;               
}
