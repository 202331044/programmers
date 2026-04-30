#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(vector<int> emergency) {
//     vector<int> answer;
//     vector<int> order(emergency.begin(), emergency.end());
    
//     sort(order.begin(), order.end(), greater<int>());
         
//     for(int n: emergency)
//     {
//         auto it = find(order.begin(), order.end(), n);
//         answer.push_back(it - order.begin() + 1);
//     }
    
    int size = emergency.size();
    
    vector<int> answer(size);
    vector<pair<int ,int>> order(size);
    
    for(int i = 0; i < size; ++i)
        order[i] = {emergency[i], i};
    
    sort(order.begin(), order.end(), greater<pair<int, int>>());
    
    for(int j = 0; j < size; ++j)
    {
        int idx = order[j].second;
        answer[idx] = j + 1;
    }
    
    return answer;
}
