#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> count(n + 2, 1);
    count[0] = count[n + 1] = 0;
    
    for(int& l : lost)
        count[l]--;
    
    for(int& r: reserve)
        count[r]++;
    
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(count[i] == 0)
        {
            if(count[i - 1] == 2) 
            {
                cnt++;
                count[i - 1]--;
            }
            else if(count[i + 1] == 2)
            {
                 cnt++;
                 count[i + 1]--;
            }
        }
        else cnt++;
    }
    
    return cnt;
}
