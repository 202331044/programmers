#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    int t = 0, z = 0;
    
    while(s != "1")
    {
        int cnt = count(s.begin(), s.end(), '1');
        z += (s.size() - cnt);
        
        string new_s;
        while(cnt)
        {
            new_s += (cnt  % 2) == 0 ? '0' : '1';
            cnt /= 2;
        }
        
        reverse(new_s.begin(), new_s.end());
        s = new_s;
        
        t++;
    }
    
    return {t, z};
}
