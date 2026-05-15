#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
//     vector<int> count(10, 0);
    
//     for(int num: numbers)
//         count[num]++;
    
//     int sum = 0;
    
//     for(int i = 0; i < 10; ++i)
//         if(count[i] == 0) sum += i;
    
//     return sum;
    
    int sum = 45;
    
    for(int num: numbers) sum -= num;
    
    return sum;
}
