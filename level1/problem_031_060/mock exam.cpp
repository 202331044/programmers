#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
//     vector<pair<int ,int>> three = {{0, 1}, {0, 2}, {0, 3}};
//     vector<vector<int>> methods = {{1,2,3,4,5}, {2,1,2,3,2,4,2,5},
//                                    {3,3,1,1,2,2,4,4,5,5}};
    
//     for(int i = 0; i < answers.size(); ++i)
//     {
//         int num = answers[i];
//         if(methods[0][i % 5] == num) three[0].first++;
//         if(methods[1][i % 8] == num) three[1].first++;
//         if(methods[2][i % 10] == num) three[2].first++;
//     }
    
//     sort(three.begin(), three.end(), [](pair<int, int>& a, pair<int, int>& b)
//          {
//              if(a.first == b.first) return a.second < b.second;
//              return a.first > b.first;
//          });
    
//     if(three[0].first != three[1].first) 
//         return {three[0].second};
//     else if(three[0].first == three[1].first && three[1].first != three[2].first) 
//         return {three[0].second, three[1].second};
//     return {three[0].second, three[1].second, three[2].second};
    
    vector<vector<int>> methods = {{1,2,3,4,5}, {2,1,2,3,2,4,2,5},
                                   {3,3,1,1,2,2,4,4,5,5}};
    vector<int> scores(3, 0);
    
    for(int i = 0; i < answers.size(); ++i)
        for(int j = 0; j < 3; ++j)
            if(methods[j][i % methods[j].size()] == answers[i]) scores[j]++;

    int maxScore = max({scores[0], scores[1], scores[2]});
    vector<int> answer;

    for(int i = 0; i < 3; ++i)
    {
        if(maxScore == scores[i])
            answer.push_back(i + 1);
    }
    
    return answer;
}
