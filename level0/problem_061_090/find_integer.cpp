#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list, int n) {
    auto it = find(num_list.begin(), num_list.end(), n);
    
    if(it != num_list.end()) return 1;
    return 0;
}
