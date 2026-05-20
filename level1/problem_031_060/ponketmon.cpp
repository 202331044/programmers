#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
//     int size = nums.size() / 2;
    
//     unordered_set<int> s;
    
//     for(int num: nums)
//         s.insert(num);
    
//     return s.size() <= size ? s.size() : size;
    
    unordered_set<int> s(nums.begin(), nums.end());
    
    return min(s.size(), nums.size()/2);
}
