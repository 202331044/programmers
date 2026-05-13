#include <string>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    vector<int> count(7, 0);
    count[a]++;
    count[b]++;
    count[c]++;
    count[d]++;
    
    set<int> s = {a, b, c, d};
    vector<int> num(s.begin(), s.end());
    
    if(num.size() == 1) return num[0] * 1111;
    if(num.size() == 4) return num[0];
    if(num.size() == 2)
    {
        int p = num[0], q = num[1];
        if(count[p] == 3) return (10 * p + q) * (10 * p + q);
        if(count[q] == 3) return (10 * q + p) * (10 * q + p);
        if(count[p] == count[q]) return (p + q) * (abs(p - q));
    }
    else
    {
        int p = num[0], q = num[1], r = num[2];
        if(count[q] == 2) return p * r;
        if(count[r] == 2) return p * q;
        return q * r;
    }
}
