#include <string>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

int solution(vector<int> num_list) {
    int sum = 0, size = num_list.size();
    
    if(size >= 11)
    {
         // for(int i = 0; i < size; ++i)
         //     sum += num_list[i];
        
        sum = accumulate(num_list.begin(), num_list.end(), 0);
    }      
    else
    {
        // sum = 1;
        // for(int i = 0; i < size; ++i) 
        //     sum *= num_list[i];
        
        sum = accumulate(num_list.begin(), num_list.end(), 1, multiplies<int>());
    }
        
    return sum;
}
