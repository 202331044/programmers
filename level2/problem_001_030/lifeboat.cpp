#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    int cnt = 0;
    int s = 0, e = people.size() - 1;
    
    while(s <= e)
    {
        if(people[s] + people[e] <= limit)
        {
            s++;
            e--;
        }
        else
            e--;
        
        cnt++;
    }
    
    return cnt;
}
