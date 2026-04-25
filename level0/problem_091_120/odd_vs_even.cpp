#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int oddSum = 0, evenSum = 0;
    
    for(int i = 0; i < num_list.size(); ++i)
    {
        if((i + 1) % 2 == 0) evenSum += num_list[i];
        else oddSum += num_list[i];
    }
    
    return evenSum > oddSum ? evenSum : oddSum;
}
