#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    transform(arr.begin(), arr.end(), arr.begin(), [k](int num)
              {
                  if(k % 2 == 0) return num + k;
                  return num * k;
              });
    
    return arr;
}
