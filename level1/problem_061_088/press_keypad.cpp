#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
//     unordered_map<int, pair<int, int>> m = {{0, pair<int, int>(3, 1)},
//         {1, pair<int, int>(0, 0)}, {2, pair<int, int>(0, 1)},
//         {3, pair<int, int>(0, 2)}, {4, pair<int, int>(1, 0)},
//         {5, pair<int, int>(1, 1)}, {6, pair<int, int>(1, 2)},
//         {7, pair<int, int>(2, 0)}, {8, pair<int, int>(2, 1)},
//         {9, pair<int, int>(2, 2)}, {10, pair<int, int>(3, 0)},
//         {11, pair<int, int>(3, 2)}};
    
//     int left = 10, right = 11;
    
//     for(const int& number: numbers)
//     {
//         if(number == 3 || number == 6 || number == 9)
//         {
//             answer += "R";
//             right = number;
//         }
//         else if(number == 1 || number == 4 || number == 7)
//         {
//             answer += "L";
//             left = number;
//         }
//         else
//         {
//             auto [x1, y1] = m[left];
//             auto [x2, y2] = m[right];
//             auto [x, y] = m[number];
            
//             int dist1 = abs(x - x1) + abs(y - y1);
//             int dist2 = abs(x - x2) + abs(y - y2);
            
//             if(dist1 == dist2)
//                 answer += (hand == "right") ? "R" : "L";
//             else
//                 answer += dist1 < dist2 ? "L" : "R";
            
//             if(answer.back() == 'L') left = number;
//             else right = number;
//         }   
//     }
    
    int left = 10, right = 12;
    
    for(int num: numbers)
    {
        if(num == 0) num = 11;
        
        if(num == 1 || num == 4 || num == 7)
            answer += "L";
        else if(num == 3 || num == 6 || num == 9)
            answer += "R";
        else
        {
            int leftDist = abs((num - 1) / 3 - (left - 1) / 3) + 
                           abs((num - 1) % 3 - (left - 1) % 3);
            
            int rightDist = abs((num - 1) / 3 - (right - 1) / 3) + 
                           abs((num - 1) % 3 - (right - 1) % 3);
            
            if(leftDist == rightDist)
                answer += (hand == "right") ? "R" : "L";
            else
                answer += (leftDist < rightDist) ? "L" : "R";
        }
        
        if(answer.back() == 'L') left = num;
        else right = num;
    }
    
    return answer;
}
