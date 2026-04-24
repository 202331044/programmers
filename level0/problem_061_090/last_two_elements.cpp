#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int size = num_list.size();
    int back = num_list[size - 1], front = num_list[size - 2];
    
    if(back > front) 
        num_list.push_back(back - front);
    else
        num_list.push_back(back * 2);
    
    return num_list;
}
