#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
//     vector<pair<int, int>> order;
    
//     for(int num: numlist)
//         order.emplace_back(abs(n - num), num);
    
//     sort(order.begin(), order.end(), [](const pair<int, int>& a, const pair<int, int>& b)
//          {
//              if(a.first == b.first) return a.second > b.second;
//              return a.first < b.first;
//          });
    
//     vector<int> answer;
//     for(auto e: order)
//         answer.push_back(e.second);
    
//     return answer;
    
    sort(numlist.begin(), numlist.end(), [n](const int& a, const int& b)
         {
             if(abs(a - n) == abs(b - n)) return a > b;
             return abs(a - n) < abs(b - n);
         });
    
    return numlist;
}
