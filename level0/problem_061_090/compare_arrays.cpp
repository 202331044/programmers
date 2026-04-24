#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
   
    if(arr1.size() > arr2.size()) return 1;
    if(arr2.size() > arr1.size()) return -1;

    int sum1{}, sum2{};
    
    for(int num: arr1) sum1 += num;
    for(int num: arr2) sum2 += num;

    if(sum1 > sum2) return 1;
    if(sum1 < sum2) return -1;
    
    return 0;
}
