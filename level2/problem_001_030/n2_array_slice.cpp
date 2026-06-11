#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right - left + 1, 0);
    
    for(long long k = left; k <= right; ++k)
    {
        int h = k / n + 1;
        int r = k % n + 1;
        int i = max(h, r);
        
        answer[k - left] = i;
    }
    
    return answer;
}
