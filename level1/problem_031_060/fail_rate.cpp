#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

vector<int> solution(int N, vector<int> stages) {
    int total = stages.size();
    vector<int> count(N + 2, 0);
    
    for(int stage: stages)
        count[stage]++;
    
    vector<tuple<ll, ll, int>> vec;
    
    for(int i = 1; i <= N; ++i)
    {
        vec.emplace_back(count[i], total, i);
        total -= count[i];
    }
    
    sort(vec.begin(), vec.end(), [](const tuple<ll, ll, int>& a, const tuple<ll, ll, int>& b)
         {
             
             ll num1 = get<1>(b) == 0 ? get<0>(a) : get<0>(a) * get<1>(b);
             ll num2 = get<1>(a) == 0 ? get<0>(b) : get<0>(b) * get<1>(a);
             
             if(num1 == num2)
                 return get<2>(a) < get<2>(b);
             
             return num1 > num2;
         });
    
    vector<int> answer;
    for(auto [a, b, c]: vec)
        answer.push_back(c);
    
    return answer;
}
