#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(auto query: queries)
    {
        int s = query[0], e = query[1], k = query[2];
        
        // if(k == 0 && s == 0)
        // {
        //     arr[0]++;
        //     continue;
        // }
        
        if(k == 0) continue;
        
        if(s % k != 0) s = (s / k + 1) * k;
        
        for(int i = s; i <= e; i += k) arr[i]++;
    }
    
    return arr;
}
