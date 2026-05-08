#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    vector<pair<int ,int>> vec;
    
    for(int i = 0; i < rank.size(); ++i)
    {
        if(attendance[i])
            vec.emplace_back(rank[i], i);
            //vec.push_back({rank[i], i});
    }
    
    sort(vec.begin(), vec.end());
    
    int a = vec[0].second;
    int b = vec[1].second;
    int c = vec[2].second;
    
    int answer = a * 10000 + b * 100 + c;

    return answer;
}
