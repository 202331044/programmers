#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int size = num_list.size();
    string odd = "", even = "";
    
    for(int i = 0; i < size; ++i)
    {
        int num = num_list[i];
        if(num % 2 == 0) even += to_string(num);
        else odd += to_string(num);
    }
    
    return stoi(odd) + stoi(even);
}
