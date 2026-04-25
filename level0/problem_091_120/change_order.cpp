#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    //vector<int> answer(num_list.begin() + n, num_list.end());
    //answer.insert(answer.end(), num_list.begin(), num_list.begin() + n);
    
    rotate(num_list.begin(), num_list.begin() + n, num_list.end());
    
    return num_list;
}
