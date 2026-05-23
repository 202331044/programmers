#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> nums) {
    int size = nums.size();
    vector<int> arr;
    
    for(int i = 0; i < size - 2; ++i)
        for(int j = i + 1; j < size - 1; ++j)
            for(int k = j + 1; k < size; ++k)
                arr.push_back(nums[i] + nums[j] + nums[k]);
    
    int cnt = 0;
    for(int num: arr)
    {
        bool isPrime = true;
        
        for(int l = 2; l * l <= num; ++l)
        {
            if(num % l == 0) 
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime) cnt++;
    }

    return cnt;
}
