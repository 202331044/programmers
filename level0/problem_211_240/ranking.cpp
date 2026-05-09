#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    int size = score.size();
    vector<pair<int, int>> sorted_score(size);
    
    for(int i = 0; i < size; ++i)
        sorted_score[i] = {score[i][0] + score[i][1], i};
    
    sort(sorted_score.begin(), sorted_score.end(), greater<pair<int, int>>());
    
    int prev = -1;
    int order = 1;
    vector<int> answer(size);
    
    for(int j = 0; j < size; ++j)
    {
        if(prev != sorted_score[j].first) order = j + 1;
        answer[sorted_score[j].second] = order;
        prev = sorted_score[j].first;
    }
    
    return answer;
}
