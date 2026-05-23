#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<bool> vec(46, false);
    
    for(int win_num: win_nums)
        vec[win_num] = true;
    
    int cnt = 0, zero = 0;
    for(int lotto: lottos)
    {
        if(vec[lotto] == true) cnt++;
        if(lotto == 0) zero++;
    }
    
    int best = zero + cnt > 1 ? 7 - (zero + cnt) : 6;
    int worst = cnt > 1 ? 7 - cnt : 6;
    
    return {best, worst};
}
