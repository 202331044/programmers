#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(s / n < 1) return {-1};
    
    int rem = s % n;
    int num = s / n;
    
    vector<int> answer(n, num);
    
    int idx = n - 1;
    while(rem--)
    {
        answer[idx]++;
        idx--;
    }
    
    return answer;
}
