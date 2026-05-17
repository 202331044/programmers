#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int cnt = 0;
    int len = p.size();
    
    for(int i = 0; i <= t.size() - len; ++i)
        if(t.substr(i, len) <= p) cnt++;

    return cnt;
}
