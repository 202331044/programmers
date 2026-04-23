#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    // for(int num: delete_list)
    //     arr.erase(remove(arr.begin(), arr.end(), num), arr.end());
    
    unordered_set<int> s(delete_list.begin(), delete_list.end());
    
    arr.erase(remove_if(arr.begin(), arr.end(), [&](int x)
              {
                  return s.count(x);
              }), arr.end());
    
    return arr;
}
