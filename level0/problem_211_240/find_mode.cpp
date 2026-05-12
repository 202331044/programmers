#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    vector<int> frequency(1001, 0);
    for(int num: array)
        frequency[num]++;
    
    int answer = 0, cnt = 0;
    for(int i = 0; i < frequency.size(); ++i)
    {
        if(cnt < frequency[i])
        {
            answer = i;
            cnt = frequency[i];
        }
        else if(cnt == frequency[i])
            answer = -1;
    }
    return answer;
}
