#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(long long begin, long long end) {
    const int INF = 10000000;
    
    vector<int> answer(end - begin + 1, 1);
    if(begin == 1) answer[0] = 0;
    
    for(int pos = begin; pos <= end; ++pos)
    {
        for(int num = 2; num <= sqrt(pos); ++num)
        {
            if(pos % num == 0)
            {
                if(pos / num <= INF)
                {
                    answer[pos - begin] = pos / num;
                    break;
                }
                else
                    answer[pos - begin] = max(answer[pos - begin], num);
            }
        }
    }
    
    return answer;
}
