#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    int a = slicer[0], b = slicer[1], c = slicer[2];
    vector<int> answer;
    
    if(n == 1)
        answer.insert(answer.end(), num_list.begin(), num_list.begin() + b + 1);
    else if(n == 2)
        answer.insert(answer.end(), num_list.begin() + a, num_list.end());
    else if(n == 3)
        answer.insert(answer.end(), num_list.begin() + a, num_list.begin() + b + 1); 
    else if(n == 4)
    {
        for(int i = a; i <= b; i += c)
            answer.push_back(num_list[i]);
    }
    
    return answer;
}
